#include "AppMainGame.h"
#include <iostream>


AppMainGame::AppMainGame() {

	taggedImg.LoadTexture("assets/bitmaps/x.bmp");
	tMan.LoadTexture("assets/bitmaps/man.bmp");
	
	text = new Text();

	texX = taggedImg.sourceRect.x;
	texY = taggedImg.sourceRect.y;
	texW = taggedImg.sourceRect.w;
	texH = taggedImg.sourceRect.h;

	dir = 1;
	count = 1;
	angle = 0.0;
}

void AppMainGame::OnDeactivate() {
	taggedImg.DestroyTexture();
	tMan.DestroyTexture();
	text = NULL;
}

void AppMainGame::OnLoop() {
	float distance = 1;//E.fps.GetSpeedFactor() * 10;
	switch(dir) {
		case 1:
			if (count < 2) {	
				if (texX + texW < E.GetWindowWidth())
					texX += distance;
				else
					dir = 2;
				
				break;
			}
			else {
				if ( texX + (texW / 2) < (E.GetWindowWidth() / 2))
					texX += distance;
				else
					dir = 2;
					break;
			}
		case 2:
			if (count < 2) {	
				if (texY + texH < E.GetWindowHeight()) {
					texY += distance;
				}
				else {
					dir = 3;
					count++;
				}
				
				break;
			}
			else {
				if ( texY + (texH / 2) < (E.GetWindowHeight() / 2))
					texY += distance;
				else
					dir = 5;
					break;
			}
		case 3:
				if (texX > 0)
					texX -= distance;
				else
					dir = 4;	
			break;
		case 4:
				if (texY > 0)
					texY -= distance;
				else
					dir = 1;
			break;
		case 5:
			if (texX > 0 && texY > 0) {
			texX -= distance;
			texY -= distance;
			texW += distance * distance;
			texH += distance * distance;
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
			texX += distance;
			texY += distance;
			texW -= distance * distance;
			texH -= distance * distance;
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
	counter++;
}

void AppMainGame::OnRender() {

	std::ostringstream convert;
	convert << counter;

	tMan.DisplayTexture((double)0);
	taggedImg.SetDestRect( (int)texX, (int)texY, (int)texH, (int)texW );
	taggedImg.DisplayTexture(angle);
	text->write( convert.str(), 20, 430);
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
