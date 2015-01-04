#ifndef APPMAINMENU_H
	#define APPMAINMENU_H

#include "engine/AppState.h"
#include <SDL2_ttf/SDL_ttf.h>
#include <iostream>
#include "engine/E.h"
#include "engine/Text.h"

class AppMainMenu : public AppState {
private:
	//static AppMainMenu Instance;
//	SDL_Surface* Box;

	int StartTime;
	Text* text = NULL;
public:
	AppMainMenu();
	void OnEvent(SDL_Event* Event);
	void OnDeactivate();
	void OnLoop();
	void OnRender();
	
	//When Things happen
	void OnKeyDown(SDL_Keycode key);

};

#endif
