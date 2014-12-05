// Use this file to declare the different parts of your game
// My documentation sux
#include "mainMenu_app.h"

enum {
	APP_NONE,
	APP_MAIN_MENU,
	APP_GAME
}

void AppStateManager::SetActiveAppState(int AppStateId) {
	if (AppStateId == APP_NONE)	ActiveAppState = 0;
	if (AppStateId == APP_MAIN_MENU) ActiveAppState = main_menu::GetInstance();
	//if (AppStateId == APP_GAME)	ActiveAppState = game::GetInstance();

	if (ActiveAppState) ActiveAppState->onActivate();
}

