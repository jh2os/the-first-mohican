#include "E.h"

EngineResources E;

EngineResources::EngineResources() {
	running = true;
	gameWindow = NULL;
	gameRenderer = NULL;
	gameSurface = NULL;
	logger = NULL;
	configs = NULL;
	

	//windowWidth = 640;
	//windowHeight = 480;
}

void EngineResources::Start() {
	// Initialize the configurations
	configs = new Configuration("config.txt");
	if(!configs->LoadConfigurations()){
		running = false;
	}
	
	// Initialize the debugger
	logger = new Logger(configs->getLoggerDirectory());
	if(logger == NULL){
		running = false;
	}
	
	// NOTE: logger is now initialized
	
	// Start SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		logger->LogError("SDL could not initialize! SDL_Error: " + string(SDL_GetError()));
		running = false;
	}

	// Start TTF
	if (TTF_Init() == -1) {
		logger->LogError("SDL_ttf could not initialize! SDL_Error: " + string(SDL_GetError()));
		running = false;
	}

	// load support for the JPG and PNG image formats (From sdl docs)
	int flags=IMG_INIT_JPG|IMG_INIT_PNG;
	int initted=IMG_Init(flags);
	if (((initted)&(flags)) != flags) {
		logger->LogError("IMG_Init: Failed to init required jpg and png support!");
		logger->LogError("IMG_Init: " + string(IMG_GetError()));
		running = false;
	}
	
	// Start Mixer
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
		logger->LogError("SDL_mixer could not initialize! SDL_Error: " + string(Mix_GetError()));
		running = false;
	}

	// Declare our window
	gameWindow = SDL_CreateWindow("11th-fret Game Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, E.configs->getScreenWidth(), E.configs->getScreenHeight(), 0);
	E.SetWindowResolution( E.configs->getScreenWidth(), E.configs->getScreenHeight());
	if(gameWindow == NULL) {
		logger->LogError("Window could not be created! SDL_Error: " + string(SDL_GetError()));
		running = false;
	}

	// Declare our Renderer
	gameRenderer = SDL_CreateRenderer( &*gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (gameRenderer == NULL) {
		logger->LogError("Renderer could not be created! SDL_Error: " + string(SDL_GetError()));
		running = false;
	}

	SDL_SetRenderDrawBlendMode(E.gameRenderer, SDL_BLENDMODE_BLEND);
	//SDL_SetTextureBlendMode(textures[i], SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor( E.gameRenderer, 255,255,255,255);

	
	// TODO this needs to be removed
	gameSurface = SDL_GetWindowSurface(gameWindow);
	
	// Welp, looks like everything is good
	logger->LogMessage("Engine started and everything initialized.");
}

void EngineResources::SetActiveAppState(int App){
	appState = NULL;
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
	
	delete appState;
	//delete gameWindow;
	//delete gameRenderer;
	//delete gameSurface;
	
	logger->LogMessage("Everything closed. Exiting Engine.");
	
	logger->Destroy();
	configs->Destroy();
	
	logger = NULL;
	configs = NULL;
	delete logger;
	delete configs;
	
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
