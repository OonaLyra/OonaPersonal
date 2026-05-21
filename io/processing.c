#include "core.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include "stb_image.h"
#include "stb_image_write.h"

/* Keep in mind, there will be little to no comments inside this
code because most of the explaining i have to do will be written
on the documentation of the projects. ALL of them.
*/
/* This function has the goal of simply drawing over
	the found blob, being only called by the nebula detection
	and will only ever be used inside it. Already exists on the
	blobtracker_old.c, but scrambled in code, i'm still making a
	solid efficient function to it here with a better UI. */

int	object_containment(Soulcatcher *img, Blob *mass)
{
	int	y;
	int	x;
	int	thicc;
	int	idx;
	int	is_border;

	thicc = 2;
	y = mass->min_y;
	while (y <= mass->max_y)
	{
		x = mass->min_x;
		while(x <= mass->max_x)
		{
			is_border = (y < mass->min_y + thicc) || (y > mass->max_y - thicc) || (x < mass->min_x + thicc) || (x > mass->max_x - thicc);
			if(is_border)
			{
            	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
				{
					idx = (y * img->width + x) * 4;
					img->data[idx] = 191;
					img->data[idx + 1] = 0;
					img->data[idx + 2] = 255;
				}
			
			}
			x++;
		}
		y++;
	}

	return (0);
}

	/* This function exists only to bear the algoryth to find blobs
	inside the devoured file and will be invoked inside the image 
	dissecting function and will only ever be used inside it.*/
int	object_watcher(Soulcatcher *img, Theeye *eye, int x, int y)
{
	int	stack_x[16384];
	int	stack_y[16384];
	int	top;
	int cx;
	int	cy;
	int	nx;
	int	ny;
	int	nrs_idx;
	int data_idx;
	int	bright;
	int	i;
	int	ratio;

	Blob *mass;
	eye->b_sum_x = 0;
	eye->b_sum_y = 0;
	eye->b_pixels = 0;
	/* this is to get the size of the blob we're currently working with
	but with a little safeguard*/
	if (eye->blob_count >= 512)
		return (0);
	mass = &eye->blobs[eye->blob_count];
	mass->min_x = x;
	mass->min_y = y;
	mass->max_x = x;
	mass->max_y = y;
	top = 0;
	stack_x[top] = x;
	stack_y[top] = y;
	top++;
	eye->visited[y * img->width + x] = 1;
	while (top > 0)
	{
		/* Just setting some stats to work with.*/
		top--;
		cx = stack_x[top];
		cy = stack_y[top];
		eye->b_sum_x += cx;
		eye->b_sum_y += cy;
		eye->b_pixels++;
		if (cx < mass->min_x)
			mass->min_x = cx;
		if (cx > mass->max_x)
			mass->max_x = cx;
		if (cy < mass->min_y)
			mass->min_y = cy;
		if (cy > mass->max_y)
			mass->max_y = cy;
		int dx[8] = {-1,0,1,-1,1,-1,0,1};
		int dy[8] = {-1,-1,-1,0,0,1,1,1};
		i = 0;
		/* Outter clipping, now octi-directional, bish */
		while (i < 8)
		{
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= 0 && nx < img->width && ny >=  0 && ny < img->height)
			{
				nrs_idx = ny * img->width + nx;
				data_idx = nrs_idx * 4;
				bright = (img->data[data_idx] + img->data[data_idx + 1] + img->data[data_idx + 2]) / 3;
				/*This code block will understand the brightness of a pixel
				and work withit accordingly*/
				if(bright > 110 && !eye->visited[nrs_idx])
				{
					if (top < 16384) /*Yes, arbitrary number to avoid overflow.*/
					{
						eye->visited[nrs_idx] = 1;
						stack_x[top] = nx;
						stack_y[top] = ny;
						top++;
					}
				}
			}
			i++;
		}
	}
	/* We kinda need to do the blobtracker a lil better at find
	what useful blobs really are, and for that
	we make some decent metrics that will be REEEEEALLY useful
	later.*/
	mass->width = mass->max_x - mass->min_x + 1;
	mass->height = mass->max_y - mass->min_y + 1;
	mass->aspect_ratio = (float)mass->width / (float)mass->height;
	mass->density = (float)eye->b_pixels / ((float)mass->width * (float)mass->height);
	/* Let's filter MORE. Prevent any weird things from being taken as objects.
	Like a pole for instance.*/
	if (mass->width < 10 || mass->height < 10)
		return (0);
	if (mass->aspect_ratio > 6.0 || mass->aspect_ratio < 0.15)
		return (0);
	ratio = (float)mass->width / (float)mass->height;
	/* And now weird tall/wide objects will have a higher ratio.*/
	if (ratio < 1.0)
		ratio = 1.0 / ratio;
	mass->aspect_ratio = ratio;
	/* We NOW count if the blob is infact useful as a blob and if it doesnt blow
	up our previously built stack of alr detected blobs.*/
	if (eye->b_pixels > 250  && eye->blob_count < 512 && mass->density > 0.20) 
	{
		eye->blobs[eye->blob_count].id = eye->blob_count;
		eye->blobs[eye->blob_count].center_x = (int)(eye->b_sum_x / eye->b_pixels);
		eye->blobs[eye->blob_count].center_y = (int)(eye->b_sum_y / eye->b_pixels);
		eye->blobs[eye->blob_count].b_pixels = eye->b_pixels;
		eye->blob_count++;
	}
	return (0);
}

/* This is the finder of funny things in the image*/
int	nebula_detection(Soulcatcher *img, Theeye *eye)
{
	int	y;
	int	x;
	int	pix_idx;
	int	data_idx;
	int bright;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			pix_idx = y * img->width + x;
			data_idx = pix_idx * 4;
			bright = (img->data[data_idx] + img->data[data_idx + 1] + img->data[data_idx + 2]) / 3;
			
			if (bright > 110 && !eye->visited[pix_idx])
			{
				object_watcher(img, eye, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void featheroryourheart(Theeye *eye)
{
	int i;
	int j;
	Blob temp;

	i = 0;
	while (i < eye->blob_count - 1)
	{
		j = 0;
		while (j < eye->blob_count - i - 1)
		{
			if (eye->blobs[j].b_pixels < eye->blobs[j + 1].b_pixels)
			{
				temp = eye->blobs[j];
				eye->blobs[j] = eye->blobs[j + 1];
				eye->blobs[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
int	image_dissecting(Soulcatcher *img, Theeye *eye)
{
	// int	i;
	int	b;
	int	max_boxes;
	/* Map for visited pixels*/
	eye->visited = (unsigned char *)calloc(img->width * img->height, 1);
	if (!eye->visited)
	{
		printf("Failed to allocate visited map.\n");
		return (1);
	}

	/*temp blob stats init so we don't actually get anymore segfaults */
	eye->b_sum_x = 0;
	eye->b_sum_y = 0;
	eye->b_pixels = 0;
	max_boxes = 8;
	nebula_detection(img, eye);
	featheroryourheart(eye);
	/*just tone down that image overall bright to
	see if it's working as intended (it is.)
	i = 0;
    while (i < img->width * img->height * 4)
	{
        if (i % 4 != 3)
            img->data[i] = img->data[i] / 2;
        i++;
    }*/
	if (eye->blob_count < 8)
		max_boxes = eye->blob_count;
	else
		max_boxes = 8;
	b = 0;
	/* let's loop through all the blobs and draw the box over each one*/
	while (b < max_boxes)
	{
		object_containment(img, &eye->blobs[b]);
		b++;
	}
	/* Here we invoke the object_exhibit drawer when ready.*/
	free(eye->visited);
	return (0);
}
