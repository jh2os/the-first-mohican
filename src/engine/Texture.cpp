#include "Texture.h"
#include <iostream>

Texture::Texture() {
	eTexture = NULL;
	w = 0;
	h = 0;
}

bool Texture::LoadTexture(std::string filename) {
	
	SDL_Surface* tmpSurface = SDL_LoadBMP( filename.c_str() );
	if (tmpSurface == NULL) printf("unable to load image \"%s\" \n",filename.c_str());
	
	// This didn't really do anything
	//SDL_SetColorKey( Box, SDL_FALSE, SDL_MapRGB( Box->format, 0, 0xFF, 0xFF ) );

	eTexture = SDL_CreateTextureFromSurface(E.gameRenderer, tmpSurface);
	if (eTexture == NULL) printf("unable to load texture\n");
	SDL_FreeSurface(tmpSurface);

	SDL_QueryTexture( eTexture, NULL, NULL, &w, &h );

	center.x = w / 2;
  center.y = h / 2;
	
	sourceRect.x = destRect.x = 0;
	sourceRect.y = destRect.x = 0;
	sourceRect.w = destRect.w = w;
	sourceRect.h = destRect.h = h;
	

	return true;
}

void Texture::SetSourceRect(int cX, int cY, int cW, int cH ) {
	sourceRect.x = cX;
	sourceRect.y = cY;
	sourceRect.w = cW;
	sourceRect.h = cH;
}

void Texture::SetDestRect(int cX, int cY, int cW, int cH ) {
	destRect.x = cX;
	destRect.y = cY;
	destRect.w = cW;
	destRect.h = cH;
}


void Texture::DisplayTexture(double angle) {
	//printf("%i %i %i %i\n", destRect.x, destRect.y, destRect.w, destRect.h);
	SDL_RenderCopyEx( E.gameRenderer, eTexture, &sourceRect, &destRect, angle, &center, SDL_FLIP_NONE);
}
