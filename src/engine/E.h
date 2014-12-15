#ifndef ENGINERESOURCES_H
#define ENGINERESOURCES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "AppState.h"
#include "Texture.h"

class EngineResources {
	public:
		// Initialization functions
		EngineResources();
		bool Start();
		void Quit();
		bool running;
		SDL_Window* gameWindow;
		SDL_Renderer* gameRenderer;
		SDL_Surface* gameSurface;
		
		AppState* appState;
		
		void SetActiveAppState(int App);
		
		void SetWindowResolution(int x, int y);
		int GetWindowWidth();
		int GetWindowHeight();

	private:
		int windowWidth;
		int windowHeight;
};

extern EngineResources E;

#endif
