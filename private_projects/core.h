#ifndef CORE_H
#define CORE_H

typedef struct
{
	int	id;
	int center_x;
	int center_y;
	int	min_x;
	int	min_y;
	int	max_x;
	int	max_y;
	int obj_index;
	int	b_pixels;
	int	width;
	int	height;
	float	density;
	float	aspect_ratio;
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
	Blob	blobs[512];
	int	blob_count;
	
} Theeye;

int	image_devouring(char *imagepath);
int	image_dissecting(Soulcatcher *img, Theeye *eye);
int nebula_detection(Soulcatcher *img, Theeye *eye);
int	essence_enacted(Soulcatcher *img, char *imagepath);
int	object_exhibit(int ky, int kx);
int	object_watcher(Soulcatcher *img, Theeye *eye, int x, int y);
int	observer(int width, int height);

#endif // CORE_H