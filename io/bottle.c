#include "core.h"
#include <stb_image.h>
#include <stb_image_write.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int	image_devouring(char *imagepath)
{
	Soulcatcher img;
	Theeye eye = {0};

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
