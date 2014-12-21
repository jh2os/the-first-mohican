#include "E.h"

EngineResources E;

EngineResources::EngineResources() {
	running = true;
	gameWindow = NULL;
	gameRenderer = NULL;
	gameSurface = NULL;

	windowWidth = 640;
	windowHeight = 480;
}

bool EngineResources::Start() {
	// Start SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	// Start TTF
	if (TTF_Init() == -1) {
		printf("SDL_ttf could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}

	 	

	// load support for the JPG and PNG image formats (From sdl docs)
	int flags=IMG_INIT_JPG|IMG_INIT_PNG;
	int initted=IMG_Init(flags);
	if (((initted)&(flags)) != flags) {
		printf("IMG_Init: Failed to init required jpg and png support!\n");
		printf("IMG_Init: %s\n", IMG_GetError());
		// handle error
	}

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) < 0) { 
		printf("SDL_mixer could not initialize! SDL_Error: %s\n", Mix_GetError());
	}

	// Declare our window
	gameWindow = SDL_CreateWindow("11th-fret Game Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth,windowHeight, 0);
	if(gameWindow == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	// Declare our Renderer
	gameRenderer = SDL_CreateRenderer( &*gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (gameRenderer == NULL) {
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	SDL_SetRenderDrawBlendMode(E.gameRenderer, SDL_BLENDMODE_BLEND);
	//SDL_SetTextureBlendMode(textures[i], SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor( E.gameRenderer, 255,255,255,255);

	
	// TODO this needs to be removed
	gameSurface = SDL_GetWindowSurface(gameWindow);
	// Welp, looks like everything is good
	return true;
}

void EngineResources::SetActiveAppState(int App){
	appState = appState->SetActiveAppState(App);
}

void EngineResources::Quit() {
	SDL_FreeSurface(gameSurface);
	SDL_DestroyRenderer(gameRenderer);
	SDL_DestroyWindow(gameWindow);
	
	appState = NULL;
	
        // Quit TTF
        TTF_Quit();
	SDL_Quit();
	Mix_CloseAudio();
	running = false;
}

void EngineResources::SetWindowResolution(int x, int y) {
	windowWidth = x;
	windowHeight = y;
}

int EngineResources::GetWindowWidth(){
	return windowWidth;
}

int EngineResources::GetWindowHeight() {
	return windowHeight;
}
