#ifndef MAN_H
#define MAN_H

#include "engine/E.h"
//#include "engine/Text.h"
#include <math.h>
#include <iostream>

enum manAnimations {
	STANDING,
	CRYINGSTART,
	CRYING,
	CRYINGEND
};

class Man {
 public:
	//Texture tMan;
	Sprite tMan;
	float manX;
	float manY;
	bool callforhelp;
	Text* help; 
	
	Man() {
		tMan.loadSpriteSheet("assets/bitmaps/ManSpritesheet.png");
		tMan.addAnimation(0,0,100,100,100,4);//Standing
		tMan.addAnimation(0,100,400,100,100,4); //Cryingstart
		tMan.addAnimation(400,100,400,100,100,4);//crying
		tMan.addAnimation(800,100,200,100,100,4); //cryingend
		tMan.setAnimation(STANDING, -1);
		manX = 0;
		manY = 100;
		callforhelp = false;
        SDL_Color red = {255, 0, 0};
		help = new Text("Transformers-Movie.ttf", 16, red);
	}
	void Follow(int newX, int newY) {

		// Our normalized distances
		float nX;
		float nY;

		// Delta x & y and find the distance
		int dX = newX - manX;
		int dY = newY - manY;
		float distance = sqrt(pow(dX, 2) + pow(dY,2));

		// if statement avoids division by 0 error
		if (distance == 0) {
			nX = 0.0;
			nY = 0.0;
			if (callforhelp) {
				tMan.queAndSetAnimation(CRYINGEND,0,0);
				tMan.queAnimation(STANDING, -1, 0);
			}
			callforhelp = false;
		}
		else {
			// Normalize the distances
			nX = dX / distance;
			nY = dY / distance;

			if (distance > 30){
				if (!callforhelp) {
					tMan.clearQue();
					tMan.setAnimation(CRYINGSTART, 1, 0);
					tMan.setAnimation(CRYING, -1, 0);
				}
				callforhelp = true;
			}
			else {
				if (callforhelp) {
					tMan.queAndSetAnimation(CRYINGEND,0,0);
					tMan.queAnimation(STANDING, -1, 0);
					
				}
				callforhelp = false;
			}
		}
		
		// Add it
		float moveX = nX * E.fps.GetSpeedFactor(100);
		float moveY = nY * E.fps.GetSpeedFactor(100);
		manX += moveX;
		manY += moveY;
	}
	void Render() {
		//tMan.SetDestRect((int)manX, (int)manY, tMan.sourceRect.w, tMan.sourceRect.h);
		//tMan.DisplayTexture(0.0);
		int thex = E.Gcamera.convertX((int)manX, E.GetWindowWidth());
		int they = E.Gcamera.convertY((int)manY, E.GetWindowHeight());

		//std::cout << manY << "\t" << they << "\t" << E.GetWindowHeight() << std::endl;

		tMan.displaySprite(
					    thex, 
					    they
					    );
		if (callforhelp) help->write(
							    "No! Come back", 
							    thex + 75, 
							    they
							    );
	}
	void Destroy() {
		tMan.destroy();
		help = NULL;
	}

};

#endif
