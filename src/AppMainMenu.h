#ifndef APPMAINMENU_H
	#define APPMAINMENU_H

#include "eflat/appState.h"
#include <SDL2/SDL.h>

class AppMainMenu : public AppState {
private:
	static AppMainMenu Instance;
	SDL_Surface* Box;

	int StartTime;
	AppMainMenu();
public:
	void OnEvent(SDL_Event* Event);
	void OnActivate();
	void OnDeactivate();
	void OnLoop();
	void OnRender(SDL_Surface* Display);
	static AppMainMenu* GetInstance();
	
	//When Things happen
	void OnKeyDown(SDL_Keycode key);

};

#endif
