#ifndef Chunk_H
	#define Chunk_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include "E.h"

class Chunk {

private:
	Mix_Chunk* chunk;

public:
	Chunk();
	
	bool Load(std::string filename);
	void Play();
	void Pause();
	void Stop();
	void Destroy();
};

#endif
