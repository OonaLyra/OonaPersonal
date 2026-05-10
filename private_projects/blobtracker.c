#include <stdio.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
/* Command to compile is: cc blobtracker.c -o blobtracker -lm*/
/* Ver 0.0.2 */
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
	long long sum_x;
	long long sum_y;
	long long white_pixels = 0;
	int	cy;
	int	cx;
	int	idx;
	int	brightness;
	int	i;

	sum_x = 0;
	sum_y = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			index = (y * width + x) * 4;

			/* Here we should like, define what is the brightness of a point.*/
			brightness = (data[index] + data[index + 1] + data[index + 2]) / 3;
			
			/* Let's define that threshold so we'll only take into account
			things that shine.*/
			if (brightness > 180)
			{
				sum_x += x;
				sum_y += y;
				white_pixels++;
			} else {
				data[index] = 0;
				data[index + 1] = 0;
				data[index + 2] = 0;
			}
			x++;
		}
		y++;
	}
	/* if we find white pixels, we calc the center to draw the UI*/
	if (white_pixels > 0)
	{
		cx = (int)(sum_x / white_pixels);
		cy = (int)(sum_y / white_pixels);
	}
	i = -50;
	while(i < 50)
	{
		/* now we draw a simple crosshair on a blob */
		/* horizontal line here*/
		if (cx + i >= 0 && cx + i < width)
		{
			idx = (cy * width + (cx + i)) * 4;
			data[idx] = 255;
			data[idx + 1] = 0;
			data[idx + 2] =  0;
		}
		/* vertical line here too*/
		if (cy + i >= 0 && cy + i < height)
		{
			idx = ((cy + i) * width + cx) * 4;
			data[idx] = 255;
			data[idx + 1] = 0;
			data[idx + 2] = 0;
		}
		i++;
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