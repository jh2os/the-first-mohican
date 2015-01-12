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

struct AnimationQueItem {
	int animation;
	int looptype;
	int startingFrame;
};

class Sprite {
 private:
	std::vector<Animation> animations;
	std::vector<AnimationQueItem> que;
	Texture spriteSheet;
	int currentAnimation;
	int currentFrame;
	int currentLoop;
	int loopLimit;
	unsigned long int targetTime;
public:
	Sprite();
	void loadSpriteSheet(std::string filename);
	int addAnimation(int x, int y, int width, int height, int frameWidth, int fps);
	int getAnimationFrame();
	void setAnimation(int animationIndex, int loop);
	void setAnimation(int animationIndex, int loop, int startingFrame);
	void queAnimation(int animationIndex, int loop, int startingFrame = 0);
	void queAndSetAnimation(int animationIndex, int loop, int startingFrame = 0);
	void clearQue();
	void displaySprite(int x, int y);
	void destroy();
};

#endif
