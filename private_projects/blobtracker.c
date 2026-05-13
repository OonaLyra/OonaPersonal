#include "core.h"
#include <stdio.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

/* Command to compile is: cc blobtracker.c processing.c -o blobtracker -lm
And to run you just ./blobtracker 'image_path.png'
Ver 0.0.5*/
int main(int argc, char *argv[])
{
	int	i;
	if (argc == 1)
	{
		printf("Not enough arguments.\nUsage: %s 'path_to/image_file.extension'\n", argv[0]);
		return (1);
	} else {
		i = 1;
		while (i < argc)
		{
			image_devouring(argv[i]);
			i++;
		}
	}
	return (0);
}