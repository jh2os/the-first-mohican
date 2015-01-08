#ifndef FPS_H
	#define FPS_H
#include <SDL2/SDL.h>

class FPS {
	private:
		unsigned int oldTime;
		unsigned int lastTime;
		float speedFactor;
		int fps;
	public:
		FPS();
		void OnLoop();
		int GetFPS();
		float GetSpeedFactor();
		float GetSpeedFactor(int distance);
		float GetSpeedFactor(float distance);
};
#endif
