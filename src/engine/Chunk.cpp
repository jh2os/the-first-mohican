#include "Chunk.h"

Chunk::Chunk(){
	chunk = NULL;
}

bool Chunk::Load(std::string filename){
	// uses Mix_LoadWAV()
	return true;
}

void Chunk::Play(){
	
}

void Chunk::Pause(){
	
}


void Chunk::Stop(){
	
}

void Chunk::Destroy(){
	Mix_FreeChunk(chunk);
	chunk = NULL;
}
