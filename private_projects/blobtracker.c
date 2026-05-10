#include <stdio.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
/* Ver. 0.0.1 */
/* A structure that i defined up here so it would be */
/* easier to work with. */
typedef struct
{
	int	id;
	int center_x;
	int center_y;
	int obj_index;
} Blob;

int	image_devouring(int	width, int height, unsigned char *data)
{
	int	x;
	int	y;
	int	index;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	int	brightness;
	unsigned char	color;

	/* to find the pixel the logic is index = (y * width + x) * channels; */
	/* to change it, the following: */
	/* data[index] to affect the RED */
	/* data[index + 1] should affect the GREEN */
	/* data[index + 2] will affect the BLUE */
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			index = (y * width + x) * 4;
			r = data[index];
			g = data[index + 1];
			b = data[index + 2];

			/* Here we should like, define what is the brightness of a point.*/
			brightness = (r + g + b) / 3;
			/* And by the threshold, if it's lower than that value
			it becomes black, if not, full white. And that's the first step of
			building a blobtracker to edit those pretty funny images like the
			one i did today :3*/
			color = (brightness > 128 ) ?  255:0;
			data[index] = color;
			data[index + 1] = color;
			data[index + 2] = color;
			x++;
		}
		y++;
	}
	stbi_write_jpg("finished_job.jpg", width, height, 4, data, 100);
	printf("Imagem devorada e cuspida pela estrela como: finished_job.jpg\n");
	return (0);
}

int	main(void)
{
	int	width;
	int	height;
	int	channels;
	unsigned char *data = stbi_load("image.png", &width, &height, &channels, 4);
	if (!data)
	{
		printf("Erro ao carregar a imagem.\n");
		return (1);
	}
	printf("Imagem carregada com sucesso: %dx%d | %d canais.\n", width, height, channels);
	image_devouring(width, height, data);
	stbi_image_free(data);
	return (0);
}
