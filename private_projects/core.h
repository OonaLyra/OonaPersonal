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

typedef struct
{
	int	b_sum_x;
	int b_sum_y;
	int	b_pixels;
	unsigned char	*visited;
	Blob	blobs[100];
	int	blob_count;
	
} Theeye;

int	image_devouring(char *imagepath);
int	image_dissecting(Soulcatcher *img, Theeye *eye);
int nebula_detection(Soulcatcher *img, Theeye *eye);
int	essence_enacted(Soulcatcher *img, char *imagepath);
int	object_exhibit(int ky, int kx);
int	object_watcher(Soulcatcher *img, Theeye *eye, int x, int y);

#endif // CORE_H