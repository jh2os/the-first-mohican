#include "AppMainGame.h"

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

void AppMainGame::OnRender() {
     SDL_FillRect( E.gameSurface, NULL, SDL_MapRGB( E.gameSurface->format, 0x00, 0x00, 0x00) );
}

AppMainGame* AppMainGame::GetInstance() {
	return &Instance;
}
