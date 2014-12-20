#ifndef MAN_H
#define MAN_H

#include "engine/E.h"
#include "engine/Text.h"
#include <math.h>
#include <iostream>

class Man {
 public:
	Texture tMan;
	float manX;
	float manY;
	bool callforhelp;
	Text* help; 
	
	Man() {
		tMan.LoadTexture("assets/bitmaps/man.bmp");
		manX = 250;
		manY = 250;
		callforhelp = false;
		help = new Text("Transformers-Movie.ttf", 16, Text::RED);
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
			callforhelp = false;
		}
		else {
			// Normalize the distances
			nX = dX / distance;
			nY = dY / distance;
			if (distance > 30)callforhelp = true;
			else callforhelp = false;
		}
		
		// Add it and slow it down by a 4th
		manX += nX / 4;
		manY += nY / 4;
			
	}
	void Render() {
		tMan.SetDestRect((int)manX, (int)manY, tMan.sourceRect.w, tMan.sourceRect.h);
		tMan.DisplayTexture(0.0);
		if (callforhelp) help->write("No! Come back", (int)manX + 75, (int)manY);
	}
	void Destroy() {
		tMan.DestroyTexture();
		help = NULL;
	}

};

#endif
