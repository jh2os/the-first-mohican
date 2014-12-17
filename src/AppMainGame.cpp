#include "AppMainGame.h"
#include <iostream>


AppMainGame::AppMainGame() {

	taggedImg.LoadTexture("assets/bitmaps/x.bmp");
	tMan.LoadTexture("assets/bitmaps/man.bmp");

	texX = taggedImg.sourceRect.x;
	texY = taggedImg.sourceRect.y;
	texW = taggedImg.sourceRect.w;
	texH = taggedImg.sourceRect.h;

	dir = 1;
	count = 1;
	angle = 0.0;
}

void AppMainGame::OnDeactivate() {

}

void AppMainGame::OnLoop() {
	switch(dir) {
		case 1:
			if (count < 2) {	
				if (texX + texW < E.GetWindowWidth())
					texX++;
				else
					dir = 2;
				
				break;
			}
			else {
				if ( texX + (texW / 2) < (E.GetWindowWidth() / 2))
					texX++;
				else
					dir = 2;
					break;
			}
		case 2:
			if (count < 2) {	
				if (texY + texH < E.GetWindowHeight()) {
					texY++;
				}
				else {
					dir = 3;
					count++;
				}
				
				break;
			}
			else {
				if ( texY + (texH / 2) < (E.GetWindowHeight() / 2))
					texY++;
				else
					dir = 5;
					break;
			}
		case 3:
				if (texX > 0)
					texX--;
				else
					dir = 4;	
			break;
		case 4:
				if (texY > 0)
					texY--;
				else
					dir = 1;
			break;
		case 5:
			if (texX > 0 && texY > 0) {
			texX--;
			texY--;
			texW += 2;
			texH += 2;
			}
			else {
				dir = 6;
				count++;
				if (count == 5)
					dir = 7;
				
			}
			break;
		case 6:
					if (texW > 0 && texH > 0) {
			texX++;
			texY++;
			texW -= 2;
			texH -= 2;
			}
			else {
				dir = 5;
			}
			break;
		case 7:
			angle += 1;
			if ( angle >= 1080)
				dir = 8;
			break;

		default:
			break;
			
	}
}

void AppMainGame::OnRender() {
	//SDL_FillRect( E.gameSurface, NULL, SDL_MapRGB( E.gameSurface->format, 0x00, 0x00, 0x00) );
	SDL_SetRenderDrawColor( E.gameRenderer, 0,0,0,255);
	//SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_NONE);
	//SDL_SetTextureAlphaMod( tex, 20);

	taggedImg.SetDestRect( texX, texY, texH, texW );
	taggedImg.DisplayTexture(angle);
	tMan.DisplayTexture((double)0);	

}

void AppMainGame::OnKeyDown(SDL_Keycode key) {
	switch(key) {
		case SDLK_ESCAPE: {
			// go to the main game
			E.Quit();
			break;		
		}
	}
}
