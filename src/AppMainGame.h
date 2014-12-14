#ifndef APPMAINGAME_H
	#define APPMAINGAME_H

#include "engine/AppState.h"
#include "engine/E.h"

class AppMainGame : public AppState {
private:
	//static AppMainGame Instance;
	SDL_Surface* Box;

	int StartTime;
public:
	//void OnEvent(SDL_Event* Event);
	void OnActivate();
	void OnDeactivate();
	void OnLoop();
	void OnRender();
	void SetActiveAppState(int AppStateID);
};

#endif
