#include "Sprite.h"

Sprite::Sprite() {
     //spriteSheet = NULL;
	currentAnimation = 0;
	currentFrame = 0;
	targetTime = 0;

}

void Sprite::loadSpriteSheet(std::string filename) {
    spriteSheet.LoadTexture(filename);
}

int Sprite::addAnimation(int x, int y, int width, int height, int frameWidth, int fps) {
	Animation temp;
	temp.x = x;
	temp.y = y;
	temp.width = width;
	temp.height = height;
	temp.frameWidth = frameWidth;
	temp.totalFrames = width / frameWidth;
	temp.fps = fps;
	
	int index = animations.size();
	animations.push_back(temp);

	return index;
}

int Sprite::getAnimationFrame() {
	return currentFrame;
}

void Sprite::setAnimation(int animationIndex, int loop) {
	currentAnimation = animationIndex;
	currentFrame = 0;
	targetTime = E.fps.getTime() + (1000 / animations[currentAnimation].fps);

}

void Sprite::setAnimation(int animationIndex, int loop, int startingFrame) {
	currentAnimation = animationIndex;
	currentFrame = startingFrame;
	targetTime = E.fps.getTime() + (1000/ animations[currentAnimation].fps);
}

void Sprite::displaySprite(int x, int y) {
	unsigned long int currentTime = E.fps.getTime();
	
	// Loop here just in case 2 or more frames should have ran inbetween the loops
	while (currentTime >= targetTime) {
		currentFrame = (currentFrame + 1 >= animations[currentAnimation].totalFrames) ? 0 : currentFrame + 1;
		targetTime = currentTime + (1000 / animations[currentAnimation].fps);
	}

	int xOffset = animations[currentAnimation].frameWidth * currentFrame;
	int yOffset = animations[currentAnimation].y;
	int xWidth = animations[currentAnimation].frameWidth;
	int yWidth = animations[currentAnimation].height;

	spriteSheet.SetSourceRect(xOffset, yOffset, xWidth, yWidth);
	spriteSheet.SetDestRect(x, y, xWidth, yWidth);
	spriteSheet.DisplayTexture((double)0);
}

void Sprite::destroy() {
	//something goes here
}
