#include "AppMainMenu.h"
#include "eflat/appStateManager.h"
#include <iostream>

AppMainMenu AppMainMenu::Instance;

AppMainMenu::AppMainMenu() {
	// Box = NULL;
	std::cout << "constructor" << std::endl;
	// nothing to set up
}

// I am assuming this is the init method
void AppMainMenu::OnActivate() {
	// set up ttf
	if(TTF_Init() == -1){
		printf("SDL_ttf could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else{
		font = TTF_OpenFont("ttf/Transformers-Movie.ttf", 32);
	}
}

void AppMainMenu::OnDeactivate() {
	std::cout << "deactivating main menu state" << std::endl;
	// Free font
        TTF_CloseFont(font);

        // Quit TTF
        TTF_Quit();
}

/*void AppMainMenu::OnEvent(SDL_Event* Event) {

}*/

void AppMainMenu::OnLoop() {
	// NOTE: I don't think we need this, at least in this class
	std::cout << "test" << std::endl;
}

void AppMainMenu::OnRender(SDL_Surface* Display) {
	// clear screen
	SDL_FillRect( Display, NULL, SDL_MapRGB( Display->format, 0xCC, 0xCC, 0xCC) );
	// display what we want
	
}

void AppMainMenu::OnKeyDown(SDL_Keycode key) {
	std::cout << key << std::endl;
	switch(key) {
		case SDLK_RIGHT: {
			AppStateManager::SetActiveAppState(2);
			break;		
		}
	}
}

AppMainMenu* AppMainMenu::GetInstance() {
	return &Instance;
}

