#include "AppMainGame.h"
#include "eflat/appStateManager.h"

AppMainGame AppMainGame::Instance;

AppMainGame::AppMainGame() {
	Box = NULL;
}

void AppMainGame::OnActivate() {

}

void AppMainGame::OnDeactivate() {

}

void AppMainGame::OnEvent(SDL_Event* Event) {

}

void AppMainGame::OnLoop() {
	
}

void AppMainGame::OnRender(SDL_Surface* Display) {
     SDL_FillRect( Display, NULL, SDL_MapRGB( Display->format, 0xFF, 0xFF, 0xFF) );
}

AppMainGame* AppMainGame::GetInstance() {
	return &Instance;
}
