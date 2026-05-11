#ifndef CORE_H
#define CORE_H

typedef struct
{
	int	id;
	int center_x;
	int center_y;
	int obj_index;
} Blob;

typedef struct
{
	int	width;
	int height;
	int channels;
	unsigned char *data;
	
} Soulcatcher;

int	image_devouring(char *imagepath);
int	image_dissecting(Soulcatcher *img);
int nebula_detection(Soulcatcher *img);
int	essence_enacted(Soulcatcher *img, char *imagepath);

#endif // CORE_H