#include "Camera.h"

Camera::Camera() {
	x = 0;
	y = 0;
	targetX = 0;
	targetY = 0;
}

void Camera::move(int moveX, int moveY) {
	x += moveX;
	y += moveY;
}

long int Camera::getX() {
	return x;
}

long int Camera::getY() {
	return y;
}

void Camera::setPosition(long int newX, long int newY) {
	x = newX;
	y = newY;
}

int Camera::convertX(long int targetx, int windowWidth) {
	return (int) targetx - getX();
}

int Camera::convertY(long int targety, int windowHeight) {
	return (int) windowHeight - targety + getY();
}
