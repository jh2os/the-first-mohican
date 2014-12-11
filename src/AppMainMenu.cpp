#include "AppMainMenu.h"
#include "eflat/appStateManager.h"
#include <iostream>

AppMainMenu AppMainMenu::Instance;

AppMainMenu::AppMainMenu() {
	Box = NULL;
}

void AppMainMenu::OnActivate() {

}

void AppMainMenu::OnDeactivate() {

}

void AppMainMenu::OnEvent(SDL_Event* Event) {

}

void AppMainMenu::OnLoop() {
	
}

void AppMainMenu::OnRender(SDL_Surface* Display) {
     SDL_FillRect( Display, NULL, SDL_MapRGB( Display->format, 0xFF, 0xFF, 0xFF) );
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

