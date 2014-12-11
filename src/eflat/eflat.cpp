#include "eflat.h"

#include "../AppStates.h"

eflat::eflat() {
	windowWidth = 640;
	windowHeight = 480;
	running = true;
	//Init();
}

eflat::eflat(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	running = true;
	//Init();
}

void eflat::Init() {

	gameWindow = NULL;
	gameSurface = NULL;

	// Initialize SDL
	if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else {
		gameWindow = SDL_CreateWindow( "Platform Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN );
		if ( gameWindow == NULL ) {
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else {
			//Get window surface
			gameSurface = SDL_GetWindowSurface( gameWindow );
			
			// set the active state to the main menu
			AppStateManager::SetActiveAppState(APP_MAIN_MENU);
			
			// calling this from outside of here, as init should only initialize itself and then be done
			//OnLoop();
			//	SDL_Delay(2000);
		}
	}
}

void eflat::OnLoop() {
	SDL_Event Event;
	while (running) {
		while(SDL_PollEvent(&Event)) {
			// NOTE: I think this is too much? Or should be handled in a different way
		  	AppStateManager::OnLoop();
		  
			OnEvent(&Event);
			OnRender();
		}
	}
}

void eflat::OnRender() {
	// render with current state screen
	AppStateManager::OnRender(gameSurface);
	// update the screen
	SDL_UpdateWindowSurface(gameWindow);
}

void eflat::OnEvent(SDL_Event* Event) {
	efEvent::OnEvent(Event);
	AppStateManager::OnEvent(Event);
}

void eflat::OnExit() {

	// I don't know why we are doing this
	// === This function automatically deactivates the appstate
	// === and clears the pointer to avoid segfaults
	AppStateManager::SetActiveAppState(APP_NONE);
	// deactivate the state
	//AppStateManager::OnDeactivate();
	
	SDL_FreeSurface(gameSurface);	
	//Destroy window
	SDL_DestroyWindow( gameWindow );
	
	// Quit SDL
	SDL_Quit();

	running = false;
}
