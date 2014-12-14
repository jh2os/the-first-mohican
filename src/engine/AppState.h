#ifndef APPSTATE_H
	#define APPSTATE_H

#include "EngineEvent.h"

class AppState : public EngineEvent {
public:
	virtual void OnActivate() = 0;
	virtual void OnDeactivate() = 0;
	virtual void OnLoop() = 0;
	//virtual void OnEvent(SDL_Event* Event);
	virtual void OnRender() = 0;
	AppState* SetActiveAppState(int AppStateID);
};
#endif
