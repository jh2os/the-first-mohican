#include "AppMainGame.h"
#include <iostream>


AppMainGame::AppMainGame() {

	level.loadMapSheet("assets/bitmaps/level1color.png");
	taggedImg.LoadTexture("assets/bitmaps/x.bmp");
	//tMan.LoadTexture("assets/bitmaps/man.bmp");
	
    SDL_Color red = {255, 0, 0};
    text = new Text("Transformers-Movie.ttf", 50, red);

    texX = (E.GetWindowWidth() / 2) - (taggedImg.sourceRect.w /2);
    texY = (E.GetWindowHeight() / 2) + (taggedImg.sourceRect.h/2);
    texW = taggedImg.sourceRect.w;
    texH = taggedImg.sourceRect.h;

    dir = 1;
    count = 1;
    angle = 0.0;
    counter = 0;
}

void AppMainGame::OnDeactivate() {
	taggedImg.DestroyTexture();
	dudebro.Destroy();
	
	dudebro.Destroy();
	text = NULL;
}

void AppMainGame::OnLoop() {
	
	//Lets call our man to the mouse pointer for he is indeed the chosen one
	int x = 0;
	int y =0;
	SDL_GetMouseState(&x, &y);

	if ( x > 540 ) {
		E.Gcamera.move(5, 0);
	}
	else if (x < 100) {
		E.Gcamera.move(-5,0);
	}

	if ( y > 380) {
		E.Gcamera.move(0, -5);
	}
	else if ( y < 100) {
		E.Gcamera.move(0, 5);
	}

	//std::cout << x << " " << y << std::endl;
	//std::cout << "mouseb: " << x << "\t " <<  y << std::endl;
	x = E.Gcamera.getX() + x;
	y = E.Gcamera.getY() + (E.GetWindowHeight() - y);
	//std::cout << "mousea: " << x << "\t " <<  y << std::endl;
	//std::cout << "dude  : " << (int)dudebro.manX << "\t " << (int)dudebro.manY << std::endl;
	//std::cout << "camera: " << E.Gcamera.getX() << "\t " << E.Gcamera.getY() << std::endl;
	dudebro.Follow(x - 50, y + 100);

	counter++;
}

void AppMainGame::OnRender() {
	
	level.render();

	std::ostringstream convert;
	convert << E.fps.GetFPS();//counter;
	std::string fpsstring = "FPS: " + convert.str(); 
	
	taggedImg.SetDestRect( 
					  E.Gcamera.convertX((int)texX, E.GetWindowWidth()), 
					  E.Gcamera.convertY((int)texY, E.GetWindowHeight()),
					  (int)texH, 
					  (int)texW 
					   );
	taggedImg.DisplayTexture(angle);
	//tMan.DisplayTexture((double)0);
	dudebro.Render();
	text->write( fpsstring, 20, 430);
}

void AppMainGame::OnKeyDown(SDL_Keycode key) {
	switch(key) {
	case SDLK_ESCAPE: {
		// go to the main game
		E.Quit();
		break;		
	}
	case SDLK_UP : {
		E.Gcamera.move(0, 20);
		break;
	}
	case SDLK_DOWN : {
		E.Gcamera.move(0, -20);
		break;
	}
	case SDLK_RIGHT : {
		E.Gcamera.move(20, 0);
		break;
	}
	case SDLK_LEFT : {
		E.Gcamera.move(-20, 0);
		break;
	}
	default : 
		break;
	}
}
