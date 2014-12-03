#ifndef __APPSTATEMANAGER_H__
	#define __APPSTATEMANAGER_H__

#include "efEvent.h"

class appState : public efEvent {

	public:
		appState();

		virtual void onActivate() = 0;
		virtual void onDeactivate() = 0;
		virtual void onLoop() = 0;
		virtual void onRender( SDL_Surface* eflatSurface ) = 0;	
};

#endif
