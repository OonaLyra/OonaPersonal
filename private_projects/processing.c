#include "core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stb_image.h"
#include "stb_image_write.h"

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
	and will only ever be used inside it.*/
	return (0);
}

int	object_watcher(Soulcatcher *img, Theeye *eye, int x, int y)
{
	/* This function exists only to bear the algoryth to find blobs
	inside the devoured file and will be invoked inside the image 
	dissecting function and will only ever be used inside it.*/
	return (0);
}

int	nebula_detection(Soulcatcher *img, Theeye *eye)
{
	int	ky;
	int	kx;
	int	y;
	int	x;
	int	nrs_pix_idx;
	int	pix_idx;
	int bright;
	int	i;

	y = 0;
	/*just tone down the image overall bright to
	see if it's working as intended (it is.)*/
	i = 0;
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
	free(eye->visited);
	return (0);
}
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