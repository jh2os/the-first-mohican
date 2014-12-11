#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include "eflat/eflat.h"

int main( int argc, char* args[] )
{
	int screen_width = 640;
	int screen_height = 480;
	
	// setup the engine
	// REMINDER: rename eflat to eleventhFretEngine or something with engine in the name
	eflat engine(screen_width, screen_height);
	
	// initialize the engine
	engine.Init();
	
	// start the engine
	engine.OnLoop();
	
	// do any necessary clean-up
	//engine.OnExit();
	// This is called automatically when the window is closed

	// done
	return 0;
}
