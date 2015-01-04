#ifndef TEXT_H
	#define TEXT_H
/*******************************************************************
        includes
********************************************************************/
//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
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
		SDL_Texture* texture;
		
		const int DEFAULT_SIZE = 32;
		char const* DEFAULT_FONT = "Transformers-Movie.ttf";
		char const* FONTS_LOCATION = "./assets/fonts/";
        const SDL_Color DEFAULT_COLOR = {255, 0, 0};
		
		std::string currentFont = DEFAULT_FONT;
		int currentSize = 32;
		SDL_Color currentColor = {255, 0, 0};
		
	public:
		/***********************************
        		colors
		************************************/
		
		/***********************************
        		methods
		************************************/
		Text();
		Text(std::string filename, int size, SDL_Color color);
		
		/*
		void setColor(SDL_Color color);
		void setFont(std::string filename);
		void setTextSize(int size);
		*/
		
		void write(std::string text, int x, int y);
};
#endif
