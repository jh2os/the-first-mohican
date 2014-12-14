#include "AppMainGame.h"


void AppMainGame::OnActivate() {

}

void AppMainGame::OnDeactivate() {

}

void AppMainGame::OnLoop() {
	
}

void AppMainGame::OnRender() {
	SDL_FillRect( E.gameSurface, NULL, SDL_MapRGB( E.gameSurface->format, 0x00, 0x00, 0x00) );
}
