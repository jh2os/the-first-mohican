#include "AppStateManager.h"

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

void AppStateManager::OnRender() {
	if (ActiveAppState) ActiveAppState->OnRender();

}

void AppStateManager::SetActiveAppState(int AppStateId) {
	if (ActiveAppState) ActiveAppState->OnDeactivate();

	if (AppStateId == AppStates::APP_NONE) ActiveAppState = 0;
	if (AppStateId == AppStates::APP_MAIN_MENU) ActiveAppState = AppMainMenu::GetInstance();
	if (AppStateId == AppStates::APP_MAIN_GAME) ActiveAppState = AppMainGame::GetInstance();

	if (ActiveAppState) ActiveAppState->OnActivate();
		
}

AppState* AppStateManager::GetActiveAppState() {
	return ActiveAppState;
}
