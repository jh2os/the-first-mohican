#include "eflat.h"

eflat::eflat() {
	windowWidth = 640;
	windowHeight = 480;
	init();
}

eflat::eflat(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	running = true;
	init();
}

void eflat::init() {

	gameWindow = NULL;
	gameSurface = NULL;

	// Initialize SDL
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else {
		gameWindow = SDL_CreateWindow( "Platform Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN );
		if ( gameWindow == NULL ) {
			printf( "window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else {
			//Get window surface
			gameSurface = SDL_GetWindowSurface( gameWindow );
			
			SDL_FillRect( gameSurface, NULL, SDL_MapRGB( gameSurface->format, 0xFF, 0xFF, 0xFF) );
	
			SDL_UpdateWindowSurface(gameWindow);

			onLoop();
			//	SDL_Delay(2000);
		}
	}
}

void eflat::onLoop() {
	SDL_Event Event;
	while (running) {
		while(SDL_PollEvent(&Event)) {
			onEvent(&Event);
		}
	}
}
void eflat::onEvent(SDL_Event* Event) {
	efEvent::OnEvent(Event);
}

void eflat::OnExit() {

	//Destroy window
	SDL_DestroyWindow( gameWindow );

	// Quit SDL
	SDL_Quit();

	running = false;
}
