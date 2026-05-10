#include "core.h"
#include <stdio.h>
#include <stdlib.h>
#include "stb_image.h"
#include "stb_image_write.h"

int	image_devouring(char *imagepath)
{
	int	width;
	int height;
	int channels;
	unsigned char *data = stbi_load(imagepath, &width, &height, &channels, 4);
	if (!data)
	{
		printf("Loading failed: %s.\n", imagepath);
		stbi_image_free(data);
		return(1);
	}
	else
	{
		printf("Okay\n");
	}
	stbi_image_free(data);
	return (0);
}

int	image_dissecting(int width, int	height, unsigned char *data)
{
	aaaaaaaaaaaaaaaaaaaaaaaa
}