#include "AppState.h"
#include "../AppMainMenu.h"
#include "../AppMainGame.h"

AppState* AppState::SetActiveAppState(int AppStateID){

	AppState* whichAppState = NULL;

	if(this!=NULL) OnDeactivate();

	if (AppStateID == 0) whichAppState = NULL;
	if (AppStateID == 1) whichAppState = new AppMainMenu();
	if (AppStateID == 2) whichAppState = new AppMainGame();
	
	return whichAppState;
}
