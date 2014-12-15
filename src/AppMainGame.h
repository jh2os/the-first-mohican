#ifndef APPMAINGAME_H
	#define APPMAINGAME_H

#include "engine/AppState.h"
#include "engine/E.h"

class AppMainGame : public AppState {
private:
	//static AppMainGame Instance
	int StartTime;

public:
	AppMainGame();
	SDL_Point center;

	Texture taggedImg;
	Texture tMan;

	int texW;
	int texH;
	int texX;
	int texY;

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
