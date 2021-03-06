#include "Engine.h"

Engine::Engine() {
	// this will set the config and debug
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
		E.fps.OnLoop();
		E.appState->OnLoop();
		OnRender();

		while(SDL_PollEvent(&Event)) {
			// NOTE: I think this is too much? Or should be handled in a different way
			OnEvent(&Event);
		}
	}
}

void Engine::OnRender() {
	SDL_RenderClear(E.gameRenderer);
	// render with current state screen
	E.appState->OnRender();
	// update the screen
	SDL_RenderPresent(E.gameRenderer);	
	//SDL_UpdateWindowSurface(E.gameWindow);
}

void Engine::OnEvent(SDL_Event* event) {
	E.appState->AppState::OnEvent(event);
	EngineEvent::OnEvent(event);
}

void Engine::OnExit() {
	E.SetActiveAppState(0);
	E.Quit();
}
