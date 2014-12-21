#include "Music.h"

Music::Music(){
	music = NULL;
}

bool Music::Load(std::string filename){
	// uses Mix_LoasMUS()
	return true;
}

void Music::Play(){
	
}

void Music::Pause(){
	
}


void Music::Stop(){
	
}

void Music::Destroy(){
	Mix_FreeMusic(music);
	music = NULL;
}
