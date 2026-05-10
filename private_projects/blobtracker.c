#include <stdio.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <stdlib.h>
/* Command to compile is: cc blobtracker.c -o blobtracker -lm*/
/* Ver 0.1.0 */
/* A structure that i defined up here so it would be */
/* easier to work with. And it's finally being used ;3*/
typedef struct
{
	int	id;
	int center_x;
	int center_y;
	int obj_index;
} Blob;

int	image_devouring(int	width, int height, unsigned char *data)
{
	int	idx;
	int	brightness;
	int	i;
	int	x;
	int	y;
	int	pix_idx;
	int	data_idx;
	int	b_pixels;
	int	ky;
	int	kx;
	int	ny;
	int	nx;
	int	nrs_pix_idx;
	int cx;
	int cy;
	int	b;
	long long 	b_sum_x;
	long long	b_sum_y;
	/* That's kind of a map the pixels already processed so we don't do
	the same thing over and over*/
	unsigned char *visited = (unsigned char *)calloc(width * height, 1);
	Blob blobs[100];
	int	blob_count = 0;
	b_sum_x = 0;
	b_sum_y = 0;
	b_pixels = 0;
	/* Threshold built once again*/
	i = 0;
	x = 0;
	y = 0;
	ky = -20;
	while (i < width * height)
	{
		idx = i * 4;
		brightness = ((data[idx] + data[idx + 1] + data[idx + 2]) / 3);
		if (brightness > 150)
		{
			data[idx] = 255;
			data[idx + 1] = 255;
			data[idx + 2] = 255;
		} else {
			data[idx] = 0;
			data[idx + 1] = 0;
			data[idx + 2] = 0;
		}
		i++;
	}
	// blob detection loop
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			pix_idx = y * width + x;
			data_idx = pix_idx * 4;
			/* Non-visited white pixel*/
			if (data[data_idx] == 255 && !visited[pix_idx])
			{
				if (blob_count >= 100)
					break;
				/* Blob meassurement algorythm*/
				b_sum_x = 0;
				b_sum_y = 0;
				b_pixels = 0;
				ky = -100;
				while (ky <= 100)
				{
					kx = -100;
					while (kx <= 100)
					{
						ny = y + ky;
						nx = x + kx;
						if (nx >= 0 && nx < width && ny >= 0 && ny < height)
						{
							nrs_pix_idx = ny * width + nx;
							if (data[nrs_pix_idx * 4] == 255 && !visited[nrs_pix_idx])
							{
								visited[nrs_pix_idx] = 1;
								b_sum_x += nx;
								b_sum_y += ny;
								b_pixels++;
							}
						}
						kx++;
					}
					ky++;
				}
				/* If blob = big enough, store it*/
				if (b_pixels > 450)
				{
					blobs[blob_count].center_x = (int)(b_sum_x / b_pixels);
					blobs[blob_count].center_y = (int)(b_sum_y / b_pixels);
					blobs[blob_count].id = blob_count;
					blob_count++;
				}

			}
			x++;
		}
		y++;
	}
	b = 0;
    while (b < blob_count)
    {
        cx = blobs[b].center_x;
        cy = blobs[b].center_y;
        ky = -50; 
        while (ky <= 50)
        {
            kx = -50;
            while (kx <= 50)
            {
                if (ky == -50 || ky == 50 || kx == -50 || kx == 50)
                {
                    ny = cy + ky;
                    nx = cx + kx;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height)
                    {
                        idx = (ny * width + nx) * 4;
                        data[idx] = 255;
                        data[idx + 1] = 0;
                        data[idx + 2] = 255;
                    }
                }
                kx++;
            }
            ky++;
        }
        b++;
    }
	stbi_write_jpg("finished_job.jpg", width, height, 4, data, 100);
	printf("Imagem devorada e cuspida pela estrela como: finished_job.jpg\n");
	free(visited);
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