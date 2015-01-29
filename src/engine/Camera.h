#ifndef CAMERA_H
#define CAMERA_H


class Camera {

 private:
	long int x;
	long int y;

	long int targetX;
	long int targetY;

 public:
	Camera();
	void move(int moveX, int moveY);
	long int getX();
	long int getY();
	void setPosition(long int x, long int y);
	void setTarget(int * x, int * y);
	int convertX(long int x, int windowWidth);
	int convertY(long int y, int windowHeight);
};

#endif
