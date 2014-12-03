#include "eflat/appstatemanager.h"

class main_menu : public appstate {

	void onActivate();
	void onDeactivate();
	void onLoop();
	void onRender();
};
