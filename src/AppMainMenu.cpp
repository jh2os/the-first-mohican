#include "AppMainMenu.h"


// I am assuming this is the init method
void AppMainMenu::OnActivate() {
	
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
	
}

void AppMainMenu::OnKeyDown(SDL_Keycode key) {
	switch(key) {
		case SDLK_RIGHT: {
			// go to the main game
			E.SetActiveAppState(2);
			break;		
		}
	}
}
