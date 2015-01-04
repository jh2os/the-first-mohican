#ifndef TEXTURE_H
	#define TEXTURE_H

#include <string>
#include <SDL2/SDL.h>

#ifdef APPLE
#include <SDL2_image/SDL_image.h>
#elif LINUX
#include <SDL2/SDL_image.h>
#elif WIN32
#endif

#include "E.h"

enum textureFlip{
	NONE,
	VERTICAL,
	HORIZONTAL
};

class Texture {

private:
	SDL_Texture* eTexture;
	int w;
	int h;
	SDL_Point center;

public:

	Texture();
	SDL_Rect sourceRect;
	SDL_Rect destRect;
	void SetSourceRect(int cX, int cY, int cW, int cH );
	void SetDestRect(int cX, int cY, int cW, int cH );
	bool LoadTexture(std::string);
	void DisplayTexture(double angle);
	void DestroyTexture();
};

#endif
