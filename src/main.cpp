#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include "eflat/eflat.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
	int screen_width = 640;
	int screen_height = 480;


	// Declare our game states here
	enum {
		NONE,
		MAIN_MENU,
		GAME
	};
	
	eflat game;
	game.quit();	
	return 0;
}
