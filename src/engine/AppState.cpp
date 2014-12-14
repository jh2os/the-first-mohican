#include "AppState.h"
#include "../AppMainMenu.h"
#include "../AppMainGame.h"

AppState* AppState::SetActiveAppState(int AppStateID){
	if(this!=NULL)this->OnDeactivate();

	if (AppStateID == 0) return 0;
	if (AppStateID == 1) return new AppMainMenu();
	if (AppStateID == 2) return new AppMainGame();

	if(AppStateID != 0) this->OnActivate();
}
