#ifndef CORE_H
#define CORE_H

typedef struct
{
	int	id;
	int center_x;
	int center_y;
	int obj_index;
} Blob;

int	image_devouring(char *imagepath);
int	image_dissecting(int width, int height, unsigned char *data);

#endif // CORE_H