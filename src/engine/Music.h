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
	/**
	 * @brief Default constructor for Music
	 */
	Music();
	
	/**
	 * @brief Loads a Music from a file
	 */	
	bool Load(std::string filename);
	
	/**
	 * @brief Plays the Music
	 */
	void Play();
	
	/**
	 * @brief Pauses the Music
	 */
	void Pause();
	
	/**
	 * @brief Stops the Music
	 */
	void Stop();
	
	/**
	 * @brief Resumes the recently paused Music
	 */
	void Resume();
	
	/**
	 * @brief Destroys the Music
	 */
	void Destroy();
};

#endif
