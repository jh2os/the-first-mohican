#include <SDL2/SDL.h>
#include "efEvent.h"
#include "appStateManager.h"

class eflat : efEvent {

	public:

	bool running;
	int windowWidth;
	int windowHeight;

	SDL_Window* gameWindow;
	SDL_Surface* gameSurface;

	
	eflat();
	eflat(int width, int height);
	
	void Init();
	void OnLoop();
	void OnEvent(SDL_Event* Event);
	void OnRender();
	void OnExit();
};
