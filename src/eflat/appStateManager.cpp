#include "appStateManager.h"

#include "../AppStates.h"

AppState* AppStateManager::ActiveAppState = 0;

void AppStateManager::OnEvent(SDL_Event* Event) {
	if (ActiveAppState)  ActiveAppState->OnEvent(Event);
}

void AppStateManager::OnActivate(){
  if (ActiveAppState) ActiveAppState->OnActivate();
}

void AppStateManager::OnDeactivate(){
  if (ActiveAppState) ActiveAppState->OnDeactivate();
}

void AppStateManager::OnLoop() {
	if (ActiveAppState) ActiveAppState->OnLoop();
}

void AppStateManager::OnRender(SDL_Surface* Display) {
	if (ActiveAppState) ActiveAppState->OnRender(Display);

}

void AppStateManager::SetActiveAppState(int AppStateId) {
	if (ActiveAppState) ActiveAppState->OnDeactivate();

	if (AppStateId == APP_NONE) ActiveAppState = 0;
	if (AppStateId == APP_MAIN_MENU) ActiveAppState = AppMainMenu::GetInstance();
	if (AppStateId == APP_MAIN_GAME) ActiveAppState = AppMainGame::GetInstance();

	if (ActiveAppState) ActiveAppState->OnActivate();
		
}

AppState* AppStateManager::GetActiveAppState() {
	return ActiveAppState;
}
