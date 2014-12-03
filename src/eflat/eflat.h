#include <SDL2/SDL.h>

class eflat {

	public:

	int windowWidth;
	int windowHeight;

	SDL_Window* gameWindow;
	SDL_Surface* gameSurface;

	
	eflat();
	eflat(int width, int height);
	
	void init();	
	int quit();
};
