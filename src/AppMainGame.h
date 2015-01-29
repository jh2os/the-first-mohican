#ifndef APPMAINGAME_H
	#define APPMAINGAME_H

#include "engine/AppState.h"
#include "engine/E.h"
#include "engine/Text.h"
#include "engine/Sprite.h"
#include "Man.h"

class AppMainGame : public AppState {
private:
	//static AppMainGame Instance
	int StartTime;

public:
	AppMainGame();
	SDL_Point center;

	Texture taggedImg;
	//Texture tMan;
	Man dudebro;

	// Map test
	Texture map[8][8];

	Text* text;

	float texW;
	float texH;
	float texX;
	float texY;

	unsigned int counter;

	int dir;
	int count;

	double angle;
	//void OnEvent(SDL_Event* Event);
	void OnDeactivate();
	void OnLoop();
	void OnRender();
	void SetActiveAppState(int AppStateID);

	//When Things happen
	void OnKeyDown(SDL_Keycode key);
};

#endif
