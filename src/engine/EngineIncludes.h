#include <SDL2/SDL.h>

#ifdef APPLE
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#elif LINUX
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#elif WIN32
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#endif

#include <vector>
#include <string>
#include <math.h>
#include <iostream>
