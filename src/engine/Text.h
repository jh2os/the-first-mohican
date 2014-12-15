#ifndef TEXT_H
	#define TEXT_H
/*******************************************************************
        includes
********************************************************************/
//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include "E.h"

class Text {
	private:
		/***********************************
        		vars
		************************************/
		TTF_Font* font;
		SDL_Rect rect;
		SDL_Surface* surface;
		
		const int DEFAULT_SIZE = 32;
		char const* DEFAULT_FONT = "Transformers-Movie.ttf";
		char const* FONTS_LOCATION = "./src/ttf/";
		const SDL_Color DEFAULT_COLOR = {0, 0, 0};
		
		int currentFont;
		int currentSize;
		
	public:
		/***********************************
        		fonts
		************************************/
		enum {
			DEFAULT
		};
		
		/***********************************
        		methods
		************************************/
		Text();
		
		void write(char* text, int x, int y);
		void write(char* text, int x, int y, int fontType, int size);
};
#endif
