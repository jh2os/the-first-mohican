#include "AppMainMenu.h"
#include <stdio.h>
#include <string.h>

AppMainMenu::AppMainMenu() {
	text = new Text();
}

void AppMainMenu::OnDeactivate() {
	
}

void AppMainMenu::OnEvent(SDL_Event* event) {
	// not being called
}

void AppMainMenu::OnLoop() {
	// magic...
	// code goes here
	// game stuff happens
}

void AppMainMenu::OnRender() {
	// clear screen
	SDL_FillRect( E.gameSurface, NULL, SDL_MapRGB( E.gameSurface->format, 0xFF, 0xFF, 0xFF) );
	// list menu options now
	std::string str = "test";
	char* chr = new char[str.length() + 1];
	strcpy(chr, str.c_str());
	text->write(chr, 0, 0);
}

void AppMainMenu::OnKeyDown(SDL_Keycode key) {
	switch(key) {
		case SDLK_ESCAPE: {
			E.Quit();
			break;
		}
		case SDLK_RIGHT: {
			// go to the main game
			E.SetActiveAppState(2);
			break;		
		}
	}
}
