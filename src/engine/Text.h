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
		char const* FONTS_LOCATION = "./assets/fonts/";
		const SDL_Color DEFAULT_COLOR = RED;
		
		std::string currentFont = DEFAULT_FONT;
		int currentSize = 32;
		SDL_Color currentColor = DEFAULT_COLOR;
		
	public:
		/***********************************
        		colors
		************************************/
		static constexpr SDL_Color WHITE = {255, 255, 255};
		static constexpr SDL_Color BLACK = {0, 0, 0};
		static constexpr SDL_Color GREEN = {0, 255, 0};
		static constexpr SDL_Color RED = {255, 0, 0};
		static constexpr SDL_Color BLUE = {0, 0, 255};
		
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
