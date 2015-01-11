#ifndef SPRITE_H
#define SPRITE_H

#include "Texture.h"

struct Animation {
	int x;
	int y;
	int width;
	int height;
	int frameWidth;
	int totalFrames;
	int fps;
};

class Sprite {
 private:
	std::vector<Animation> animations;
	Texture spriteSheet;
	int currentAnimation;
	int currentFrame;
	unsigned long int targetTime;
public:
	Sprite();
	void loadSpriteSheet(std::string filename);
	int addAnimation(int x, int y, int width, int height, int frameWidth, int fps);
	int getAnimationFrame();
	void setAnimation(int animationIndex, int loop);
	void setAnimation(int animationIndex, int loop, int startingFrame);
	void displaySprite(int x, int y);
	void destroy();
};

#endif
