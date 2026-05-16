#include "core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stb_image.h"
#include "stb_image_write.h"

/* Keep in mind, there will be little to no comments inside this
code because most of the explaining i have to do will be written
on the documentation of the projects. ALL of them.
*/
int	image_devouring(char *imagepath)
{
	Soulcatcher img;
	Theeye eye;
	img.data = stbi_load(imagepath, &img.width, &img.height, &img.channels, 4);
	if (!img.data)
	{
		printf("Loading failed: %s.\n", imagepath);
		stbi_image_free(img.data);
		return(1);
	}
	else
	{
		image_dissecting(&img, &eye);

		printf("Object successfully initiated: %dx%d | %d canais.\n", img.width, img.height, img.channels);
		essence_enacted(&img, imagepath);
	}
	stbi_image_free(img.data);
	return (0);
}

int	object_exhibit(int ky, int kx)
{
	/* This function has the goal of simply drawing over
	the found blob, being only called by the nebula detection
	and will only ever be used inside it. Already exists on the
	blobtracker_old.c, but scrambled in code, i'm still making a
	solid recursive function to it.*/
	return (0);
}

	/* This function exists only to bear the algoryth to find blobs
	inside the devoured file and will be invoked inside the image 
	dissecting function and will only ever be used inside it.*/
int	object_watcher(Soulcatcher *img, Theeye *eye, int x, int y)
{
	int	stack_x[8192];
	int	stack_y[8192];
	int	top;
	int cx;
	int	cy;
	int	nx;
	int	ny;
	int	nrs_idx;
	int data_idx;
	int	bright;
	int	i;

	eye->b_sum_x = 0;
	eye->b_sum_y = 0;
	eye->b_pixels = 0;
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
		cy = stack_x[top];
		eye->b_sum_x += cx;
		eye->b_sum_y += cy;
		eye->b_pixels++;
		int dx[4] = {0, 0, -1, 1};
		int dy[4] = {-1, 1, 0, 0};
		i = 0;
		/* Outter clipping */
		while (i < 4)
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
				if(bright < 75 && !eye->visited)
				{
					if (top < 8192) /*Yes, arbitrary number to avoid overflow.*/
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
		/* We count the blob if it's big enough and if it doesnt blow
		up our previously built stack of alr detected blobs.*/
		if (eye->b_pixels > 450 && eye->blob_count < 100) 
		{
			eye->blobs[eye->blob_count].id = eye->blob_count;
			eye->blobs[eye->blob_count].center_x = (int)(eye->b_sum_x / eye->b_pixels);
			eye->blobs[eye->blob_count].center_y = (int)(eye->b_sum_y / eye->b_pixels);
		}
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
	int	i;

	y = 0;
	i = 0;
	/*just tone down the image overall bright to
	see if it's working as intended (it is.)*/
    while (i < img->width * img->height * 4)
	{
        if (i % 4 != 3)
            img->data[i] = img->data[i] / 2;
        i++;
    }
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			pix_idx = (y * img->width + x) * 4;
			bright = (img->data[pix_idx] + img->data[pix_idx + 1] + img->data[pix_idx + 2]) / 3;
			if (bright > 75 && !eye->visited[pix_idx])
			{
				object_watcher(img, eye, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	image_dissecting(Soulcatcher *img, Theeye *eye)
{
	int	i;
	/* Map for visited pixels*/
	eye->visited = (unsigned char *)calloc(img->width * img->height, 1);

	/*temp blob stats */
	eye->b_sum_x = 0;
	eye->b_sum_y = 0;
	eye->b_pixels = 0;
	nebula_detection(img, eye);
	/* Here we invoke the UI drawer.*/
	free(eye->visited);
	return (0);
}
/* This right here saves the file with the name of the original name
plus _renewed.jpg at the end.*/
int	essence_enacted(Soulcatcher *img, char *imagepath)
{
	char	*essence = strrchr(imagepath, '/');
	char	karma[256];
	if (essence)
		essence++;
	else
	 	essence = imagepath;
	strcpy(karma, essence);
	char	*dot = strrchr(karma, '.');
	if (dot)
		*dot = '\0';
	strcat(karma, "_renewed.jpg");
	stbi_write_jpg(karma, img->width, img->height, 4, img->data, 100);
	printf("Content spat out by the star as: %s\n", karma);
	return (0);
}