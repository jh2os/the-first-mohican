#ifndef TEXT_H
	#define TEXT_H
/*******************************************************************
        includes
********************************************************************/
//Using SDL and standard IO
#include <SDL2/SDL.h>

#ifdef APPLE
#include <SDL2_ttf/SDL_ttf.h>
#elif LINUX
#include <SDL2/SDL_ttf.h>
#elif WIN32
#include "SDL_ttf.h"
#endif

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
		/**
		 * @brief Default constructor for Text
		 */
		Text();
		
		/**
		 * @brief Specialized constructor for Text
		 *
		 * @param filename the filename of the ttf
		 * @param size the size of the text
		 * @param color the color of the text
		 */
		Text(std::string filename, int size, SDL_Color color);

		/**
		 * @brief Writes text to the screen
		 *
		 * @param text the text to write
		 * @param size the x coordinate to start writing
		 * @param color the y coordinate to start writing
		 */
		void write(std::string text, int x, int y);
};
#endif
