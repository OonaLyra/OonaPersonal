#include "core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stb_image.h"
#include "stb_image_write.h"

int	image_devouring(char *imagepath)
{
	Soulcatcher img;
	img.data = stbi_load(imagepath, &img.width, &img.height, &img.channels, 4);
	if (!img.data)
	{
		printf("Loading failed: %s.\n", imagepath);
		stbi_image_free(img.data);
		return(1);
	}
	else
	{
		image_dissecting(&img);

		printf("Object successfully initiated: %dx%d | %d canais.\n", img.width, img.height, img.channels);
		essence_enacted(&img, imagepath);
	}
	stbi_image_free(img.data);
	return (0);
}

int	nebula_detection(Soulcatcher *img)
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
	see if it's working as intended*/
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

int	image_dissecting(Soulcatcher *img)
{
	int	b_sum_x;
	int b_sum_y;
	int	b_pixels;
	int	i;
	/* Map for visited pixels*/
	unsigned char	*visited = (unsigned char *)calloc(img->width * img->height, 1);

	/*temp blob stats */
	b_sum_x = 0;
	b_sum_y = 0;
	b_pixels = 0;
	nebula_detection(img);
	free(visited);
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