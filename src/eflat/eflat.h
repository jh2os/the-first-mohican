#include <SDL2/SDL.h>
#include "efEvent.h"

class eflat : efEvent {

	public:

	bool running;
	int windowWidth;
	int windowHeight;

	SDL_Window* gameWindow;
	SDL_Surface* gameSurface;

	
	eflat();
	eflat(int width, int height);
	
	void init();
	void onLoop();
	void onEvent(SDL_Event* Event);	
	void OnExit();
};
