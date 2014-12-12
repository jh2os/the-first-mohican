#ifndef APPMAINMENU_H
	#define APPMAINMENU_H

#include "engine/AppState.h"
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "engine/AppStateManager.h"

class AppMainMenu : public AppState {
private:
	static AppMainMenu Instance;
//	SDL_Surface* Box;

	int StartTime;
	TTF_Font* font = NULL;
	AppMainMenu();
public:
	//void OnEvent(SDL_Event* Event);
	void OnActivate();
	void OnDeactivate();
	void OnLoop();
	void OnRender(SDL_Surface* Display);
	static AppMainMenu* GetInstance();
	
	//When Things happen
	void OnKeyDown(SDL_Keycode key);

};

#endif
