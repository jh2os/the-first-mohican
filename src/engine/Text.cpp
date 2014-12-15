#include "Text.h"

Text::Text() {
	// set font to the default font
	font = TTF_OpenFont("./src/ttf/Transformers-Movie.ttf", DEFAULT_SIZE);
	surface = NULL;
	
	currentFont = Text::DEFAULT;
	currentSize = DEFAULT_SIZE;
}

void Text::write(char* text, int x, int y){
	write(text, x, y, DEFAULT, DEFAULT_SIZE);
}

void Text::write(char* text, int x, int y, int fontType, int size){
	
	// check that x,y is on the screen
	if(x < 0 || y < 0){
		// raise an error
		return;
	}
	rect.x = x;
	rect.y = y;
	
	// check to see if we need to change the font
	if(fontType != currentFont || size != currentSize){
		//const char* newFont = "Transformers-Movie.ttf";
		//font = TTF_OpenFont(newFont, size);
	}
	if(font != NULL){
		surface = TTF_RenderText_Solid(font, text, DEFAULT_COLOR);
	}
	else{
		std::cout << "font was null!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	}
	SDL_BlitSurface(surface, NULL, E.gameSurface, &rect);
	SDL_FreeSurface(surface);
	surface = NULL;
}
