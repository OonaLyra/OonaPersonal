#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"

void	show_usage(char* prog_name)
{
	fprintf(stderr, "Command usage\n");
	fprintf(stderr, "%s -cam <width> <height>\n", prog_name);
	fprintf(stderr,"%s -img <file/path> <file/path>...\n", prog_name);
	fprintf(stderr,"%s -vid <file/path>(upcoming feature)\n", prog_name);
}

int	main(int argc, char *argv[])
{
	int	width;
	int	height;
	int	i;

	i = 2;
	if (argc < 2)
	{
		fprintf(stderr,"[DIAGNOSTIC] Not enough arguments.\n");
		show_usage(argv[0]);
		return (1);
	}
	if (strcmp(argv[1], "-cam") == 0)
	{
		if (argc < 4)
		{
			fprintf(stderr,"[DIAGNOSTIC] Incorrect usage.\n");
			show_usage(argv[0]);
			return (1);
		}
		width = atoi(argv[2]);
		height = atoi(argv[3]);
		fprintf(stderr,"[MASAMI] Waking up.\n");
		fprintf(stderr,"[MASAMI] Sight module starting: %dx%d.\n", width, height);
		observer(width, height);

	}
	else if (strcmp(argv[1], "-img") == 0)
	{
		if (argc < 3)
		{
			fprintf(stderr,"[DIAGNOSTIC] Incorrect usage.\n");
			show_usage(argv[0]);
			return (1);
		}
		while (i < argc)
		{
			image_devouring(argv[i]);
			i++;
		}
		fprintf(stderr,"[MASAMI] Waking up.\n");
	}
	show_usage(argv[0]);
	return (1);
}