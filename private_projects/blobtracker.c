#include "core.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

/* Command to compile is: make.
or cc -Wall -Wextra -O2 -o blobtracker blobtracker.o processing.o -lm
And to run you just ./blobtracker 'image_path.png'
or if live, ffmpeg -f v4l2 -video_size 640x480 -i /dev/video0 -f rawvideo -pix_fmt rgba - | ./blobtracker -cam 640 480 | ffplay -f rawvideo -pixel_format rgba -video_size 640x480 -
Ver 0.0.8 */
int main(int argc, char *argv[])
{
	int	i;
	char	*image;
	char	*video;
	char	*stream;
	int	width;
	int	height;


	image = "-img";
	video = "-vid";
	stream = "-cam";
	if (argc == 1)
	{
		printf("Not enough arguments.\nUsage: %s 'path_to/image_file.extension'\n", argv[0]);
		return (1);
	} else {
		if(strcmp(argv[1], "-img") == 0)
		{
			i = 2;
			while (i < argc)
			{
				image_devouring(argv[i]);
				i++;
			}
		}
		else if (strcmp(argv[1], "-vid") == 0)
		{
			/* Here i'll add a video processing function once it exists*/
		}
		else if (strcmp(argv[1], "-cam") == 0)
		{
			width = atoi(argv[2]);
			height = atoi(argv[3]);
			if(width <= 0 || height <= 0)
			{
				fprintf(stderr, "I cannot see through this lenses.\n");
				return (1);
			}
			else
			{
				observer(width, height);
			}
		}
	}
	return (0);
}