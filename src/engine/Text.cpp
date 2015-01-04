#include "Text.h"

Text::Text() {
	// set font to the default font
	std::string loc = std::string(FONTS_LOCATION) + DEFAULT_FONT;
	font = TTF_OpenFont(loc.c_str(), DEFAULT_SIZE);
	texture = NULL;
	std::cout << currentFont << std::endl;
}

Text::Text(std::string filename, int size, SDL_Color color) {
	// NOTE: change the open font to reflect filename
	std::string loc = std::string(FONTS_LOCATION) + DEFAULT_FONT;
	font = TTF_OpenFont(loc.c_str(), size);
    std::cout << loc << std::endl;
	texture = NULL;
	currentFont = filename;
	currentSize = size;
	currentColor = color;
}

/*
void Text::setColor(SDL_Color color){
	currentColor = color;
}

void Text::setFont(std::string filename){
	currentFont = filename;
	std::string loc = std::string(FONTS_LOCATION) + currentFont;
	font = TTF_OpenFont(loc.c_str(), currentSize);
}

void Text::setTextSize(int size){
	currentSize = size;
	std::string loc = std::string(FONTS_LOCATION) + currentFont;
	font = TTF_OpenFont(loc.c_str(), currentSize);
}
*/

void Text::write(std::string text, int x, int y){
	// check that x,y is on the screen
	if(x < 0 || y < 0){
		// raise an error
		return;
	}
	rect.x = x;
	rect.y = y;
	
	if(font != NULL){
		SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), currentColor);
		if(surface != NULL){
			texture = SDL_CreateTextureFromSurface(E.gameRenderer, surface);
			SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
			SDL_RenderCopy(E.gameRenderer, texture, NULL, &rect);
			SDL_FreeSurface(surface);
			SDL_DestroyTexture(texture);
		}
	}
	else{
		std::cout << "font was null!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	}
	//SDL_BlitSurface(surface, NULL, E.gameSurface, &rect);
}
