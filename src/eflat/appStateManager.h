#ifndef APPSTATEMANAGER_H_
	#define APPSTATEMANAGER_H_

#include "appState.h"

class AppStateManager {
private:
	static AppState* ActiveAppState;
public:
	// These are passthrough functions
	static void OnEvent(SDL_Event* Event);
	static void OnActivate();
	static void OnDeactivate();
	static void OnLoop();
	static void OnRender(SDL_Surface* Display);

	// These functions are not passthrough
	static void SetActiveAppState(int AppStateID);
        static AppState* GetActiveAppState();
};
#endif
