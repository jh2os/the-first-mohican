#include "FPS.h"

FPS::FPS() {

	oldTime = 0;
	lastTime = 0;
	speedFactor = 0.0;
	fps = 0;
}

void FPS::OnLoop() {
	unsigned int currentTick = SDL_GetTicks();
	speedFactor = ((currentTick - lastTime) / 1000.0f);
	fps = 1 / speedFactor;
	lastTime = currentTick;
}

int FPS::GetFPS() {
	return fps;
}

float FPS::GetSpeedFactor() {
	return speedFactor;
}

float FPS::GetSpeedFactor(int distance) {
	return speedFactor * distance;
}

float FPS::GetSpeedFactor(float distance) {
	return speedFactor * distance;
}
