#ifndef FPS_H
	#define FPS_H
#include <SDL2/SDL.h>

class FPS {
	private:
		unsigned int oldTime;
		int lastTime;
		float speedFactor;
		int numFrames;
		int frames;
	public:
		FPS();
		void OnLoop();
		int GetFPS();
		float GetSpeedFactor();
};
#endif
