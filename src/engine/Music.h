#ifndef Music_H
	#define Music_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
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
