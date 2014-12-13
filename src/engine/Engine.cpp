#include "Engine.h"

Engine::Engine() {
  E.Start();
}

Engine::Engine(int width, int height) {
  // We need to look at ways to set the res...
  E.Start();
}

void Engine::Init() {
  AppStateManager::SetActiveAppState(AppStates::APP_MAIN_MENU);
}

void Engine::OnLoop() {
	SDL_Event Event;
	while (E.running) {
		while(SDL_PollEvent(&Event)) {
			// NOTE: I think this is too much? Or should be handled in a different way
		  	AppStateManager::OnLoop();
		  
			OnEvent(&Event);
			OnRender();
		}
	}
}

void Engine::OnRender() {
	// render with current state screen
  std::cout << "Here" << std::endl;
	AppStateManager::OnRender();
	// update the screen
	std::cout << "There" << std::endl;
	SDL_UpdateWindowSurface(E.gameWindow);
}

void Engine::OnEvent(SDL_Event* Event) {
	EngineEvent::OnEvent(Event);
	AppStateManager::OnEvent(Event);
}

void Engine::OnExit() {

  AppStateManager::SetActiveAppState(AppStates::APP_NONE);
  E.Quit();
}
