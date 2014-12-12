#ifndef APPMAINGAME_H
	#define APPMAINGAME_H

#include "engine/AppState.h"
// uncomment if needed
//#include "engine/AppStateManager.h"

class AppMainGame : public AppState {
private:
	static AppMainGame Instance;
	SDL_Surface* Box;

	int StartTime;
	AppMainGame();
public:
	void OnEvent(SDL_Event* Event);
	void OnActivate();
	void OnDeactivate();
	void OnLoop();
	void OnRender(SDL_Surface* Display);
	static AppMainGame* GetInstance();
};

#endif
