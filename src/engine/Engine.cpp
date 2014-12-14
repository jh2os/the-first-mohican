#include "Engine.h"

Engine::Engine() {
	E.Start();
}

Engine::Engine(int width, int height) {
	// We need to look at ways to set the res...
	E.Start();
}

void Engine::Init() {
 	E.SetActiveAppState(1);
}

void Engine::OnLoop() {
	SDL_Event Event;
	while (E.running) {
		while(SDL_PollEvent(&Event)) {
			// NOTE: I think this is too much? Or should be handled in a different way
		  	OnEvent(&Event);
		  	E.appState->OnLoop();
			OnRender();
		}
	}
}

void Engine::OnRender() {
	// render with current state screen
	E.appState->OnRender();
	// update the screen
	SDL_UpdateWindowSurface(E.gameWindow);
}

void Engine::OnEvent(SDL_Event* event) {
	EngineEvent::OnEvent(event);
	E.appState->OnEvent(event);
}

void Engine::OnExit() {
	//E.SetActiveAppState(0);
	E.Quit();
}
