#include "AppMainMenu.h"
#include <stdio.h>
#include <string.h>

AppMainMenu::AppMainMenu() {
	// default
	//text = new Text();
	
	// custom
	text = new Text("Transformers-Movie.ttf", 50, Text::RED);
	
	// both work!
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
	//SDL_FillRect( E.gameSurface, NULL, SDL_MapRGB( E.gameSurface->format, 0xFF, 0xFF, 0xFF) );
	// list menu options now
	
	// testing.....
	text->write("test1", 0, 0);
	text->write("test2", 0, 50);
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
		case SDLK_LEFT: {
			// go to the main game
			std::cout << "this shall be the snake! game" << std::endl;
			break;
		}
	}
}
