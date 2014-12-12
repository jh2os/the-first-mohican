#ifndef APPSTATE_H
	#define APPSTATE_H

#include "EngineEvent.h"

class AppState : public EngineEvent {
public:
	AppState();
	virtual void OnActivate() = 0;
	virtual void OnDeactivate() = 0;
	virtual void OnLoop() = 0;
//	virtual void OnEvent(SDL_Event* Event) = 0;
	virtual void OnRender(SDL_Surface* Display) = 0;
};
#endif
