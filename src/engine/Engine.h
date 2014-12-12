#include <SDL2/SDL.h>
#include "EngineEvent.h"
#include "AppStateManager.h"

class Engine : EngineEvent {

	public:

	bool running;
	int windowWidth;
	int windowHeight;

	SDL_Window* gameWindow;
	SDL_Surface* gameSurface;

	
	Engine();
	Engine(int width, int height);
	
	void Init();
	void OnLoop();
	void OnEvent(SDL_Event* Event);
	void OnRender();
	void OnExit();
};
