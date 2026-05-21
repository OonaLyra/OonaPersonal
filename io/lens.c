#include "core.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>

/* Here we're going to use the fread and fwrite to get video from the cam*/
int	observer(int width, int height)
{
	Soulcatcher img;
	size_t	frame_size;
	size_t	bytes_read;
	long	frame_count;

	FILE *pipe_in;
	char	ffmpeg_cmd[512];
	img.width = width;
	img.height = height;
	img.channels = 4;
	frame_size = width * height * 4;
	frame_count = 0;

	img.data = (unsigned char *)malloc(frame_size);
	if (!img.data) return (1);
	snprintf(ffmpeg_cmd, sizeof(ffmpeg_cmd),"ffmpeg -loglevel quiet -f v4l2 -video_size %dx%d -i /dev/video0 -f rawvideo -pix_fmt rgba -", width, height);
	pipe_in = popen(ffmpeg_cmd, "r");
	if (!pipe_in)
	{
		fprintf(stderr, "[DIAGNOSTIC] - Failed to start the observer.\n");
		fprintf(stderr,"[MASAMI] - Shutting down.\n");
		free(img.data);
		return (1);
	}
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "[DIAGNOSTIC] - SDL Initialization Error: %s\n", SDL_GetError());
		return (1);
	}
	SDL_Window *window = SDL_CreateWindow("[MASAMI] - GLaring", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, width, height);
	int running = 1;
	SDL_Event event;
	fprintf(stderr, "[DIAGNOSTIC] - observer active | (%dx%d)\n", width, height);
	while(running)
	{
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = 0;
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
				running = 0;
		}
		bytes_read = fread(img.data, 1, frame_size, pipe_in);
		if (bytes_read < frame_size)
		{
			fprintf(stderr, "[DIAGNOSTIC] - Observer interrupted | Video stream ended.\n");
			break;
		}
		Theeye eye = {0};
		image_dissecting(&img, &eye);
		SDL_UpdateTexture(texture, NULL, img.data, width * 4);
		SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
		frame_count++;
		if (frame_count % 30 == 0)
		{
			fprintf(stderr, "[TELEMETRY] Frames: %ld | Entities: %d\n", frame_count, eye.blob_count > 8 ? 8 : eye.blob_count);
		}
	}
	fprintf(stderr, "[CLEANUP] Disassembling interfaces.\n");
	fprintf(stderr, "[MASAMI] Shutting down.\n");
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
 	SDL_Quit();
	pclose(pipe_in);
 	free(img.data);
	return (0);
}
