#include "AppMainGame.h"
#include "engine/AppStateManager.h"

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
     SDL_FillRect( Display, NULL, SDL_MapRGB( Display->format, 0x00, 0x00, 0x00) );
}

AppMainGame* AppMainGame::GetInstance() {
	return &Instance;
}
