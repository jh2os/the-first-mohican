#include "Sprite.h"

Sprite::Sprite() {
     //spriteSheet = NULL;
	currentAnimation = 0;
	currentFrame = 0;
	targetTime = 0;
	currentLoop = 0;
	loopLimit = -1;

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
	currentLoop = 0;
	loopLimit = loop;
	targetTime = E.fps.getTime() + (1000 / animations[currentAnimation].fps);

}

void Sprite::setAnimation(int animationIndex, int loop, int startingFrame) {
	currentAnimation = animationIndex;
	currentFrame = startingFrame;
	currentLoop = 0;
	loopLimit = loop;
	targetTime = E.fps.getTime() + (1000/ animations[currentAnimation].fps);
}

void Sprite::queAnimation(int animationIndex, int loop, int startingFrame) {
	AnimationQueItem temp;
	temp.animation = animationIndex;
	temp.looptype = loop;
	temp.startingFrame = startingFrame;
	que.push_back(temp);
}

void Sprite::clearQue() {
	que.clear();
}

void Sprite::displaySprite(int x, int y) {
	unsigned long int currentTime = E.fps.getTime();
	
	// Loop here just in case 2 or more frames should have ran inbetween the loops
	while (currentTime >= targetTime) {
		//std::cout << currentTime << std::endl;
		if ( currentLoop < loopLimit || loopLimit == -1 ) {
			if (currentFrame + 1 >= animations[currentAnimation].totalFrames) {
				currentFrame = 0; 
				currentLoop++;
			} 
			else {
				currentFrame += 1;
			}
			targetTime = currentTime + (1000 / animations[currentAnimation].fps);
		}
		else {

			if(que.size() > 0) {
				que.erase(que.begin());
				setAnimation(que[0].animation, que[0].looptype);
			}
			else {
				targetTime = currentTime + (1000 / animations[currentAnimation].fps);
			}
		}
	}

	int xOffset = animations[currentAnimation].x + animations[currentAnimation].frameWidth * currentFrame;
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
