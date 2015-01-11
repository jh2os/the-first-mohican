#ifndef MAN_H
#define MAN_H

#include "engine/E.h"
//#include "engine/Text.h"
#include <math.h>
#include <iostream>

enum manAnimations {
	STANDING,
	CRYING
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
		tMan.addAnimation(0,0,100,100,100,1);
		tMan.addAnimation(0,100,500,100, 100, 4);
		tMan.setAnimation(STANDING, -1);
		manX = 250;
		manY = 250;
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
			if (callforhelp) tMan.setAnimation(STANDING, -1);
			callforhelp = false;
		}
		else {
			// Normalize the distances
			nX = dX / distance;
			nY = dY / distance;

			if (distance > 30){
				if (!callforhelp) tMan.setAnimation(CRYING, -1);
				callforhelp = true;
			}
			else {
				if (callforhelp) tMan.setAnimation(STANDING, -1);
				callforhelp = false;
			}
		}
		
		// Add it
		float moveX = nX *  E.fps.GetSpeedFactor(100);
		float moveY = nY * E.fps.GetSpeedFactor(100);
		manX += moveX;
		manY += moveY;
	}
	void Render() {
		//tMan.SetDestRect((int)manX, (int)manY, tMan.sourceRect.w, tMan.sourceRect.h);
		//tMan.DisplayTexture(0.0);
		tMan.displaySprite((int)manX, (int)manY);
		if (callforhelp) help->write("No! Come back", (int)manX + 75, (int)manY);
	}
	void Destroy() {
		tMan.destroy();
		help = NULL;
	}

};

#endif
