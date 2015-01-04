#ifndef Music_H
	#define Music_H

#include <string>
#include <SDL2/SDL.h>

#ifdef APPLE
#include <SDL2_mixer/SDL_mixer.h>
#elif LINUX
#include <SDL2/SDL_mixer.h>
#elif WIN32
#endif

#include "E.h"

class Music {

private:
	Mix_Music* music;

public:
	Music();
	
	bool Load(std::string filename);
	void Play();
	void Pause();
	void Stop();
	void Destroy();
};

#endif
