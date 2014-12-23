#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include "engine/Engine.h"

int main( int argc, char* args[] )
{
	//int screen_width = 640;
	//int screen_height = 480;
	
	// setup the engine
	// REMINDER: rename eflat to eleventhFretEngine or something with engine in the name
	Engine engine;
	
	if(!E.running){
		cout << "exiting already?" << endl;
		return 1;
	}
	
	cout << "getting staff done" << endl;
	
	// initialize the engine
	engine.Init();
	
	// start the engine
	engine.OnLoop();

	// done
	return 0;
	
	switch(1){
	case 1:
		std::cout << "hello" << std::endl;
	case 2:
		std::cout << "hello" << std::endl;
		break;
	case 3:
		std::cout << "this was a triumph" << std::endl;
		break;
	}
}
