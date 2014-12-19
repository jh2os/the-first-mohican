#include "FPS.h"

FPS::FPS() {

	oldTime = 0;
	lastTime = 0;
	speedFactor = 0;
	frames = 0;
	numFrames = 0;
}

void FPS::OnLoop() {
	unsigned int currentTick = SDL_GetTicks();
	if( oldTime + 1000 < currentTick) {
		oldTime = currentTick;
		numFrames = frames;
		frames = 0;
	}

	speedFactor = ((currentTick - lastTime) / 1000.0f) * 64.0f;
	lastTime = currentTick;
	frames++;
}

int FPS::GetFPS() {
	return numFrames;
}

float FPS::GetSpeedFactor() {
	return speedFactor;
}
