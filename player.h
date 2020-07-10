#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "animatedSprite.h"
#include "graphics.h"
#include "globals.h"

class Player : public AnimatedSprite {
public:
	//default constructor
	Player();

	//custom constructor
	Player(Graphics& grpahics, float x, float y);

	//draw method for player class
	void draw(Graphics& graphics);

	//update method
	void update(float elapsedTime);

	//move player left -delta x
	void moveLeft();
	//move player right +delta x
	void moveRight();
	//stop moving player
	void stopMoving();

	//override abstract functions in animatedSprite
	virtual void animationDone(string currentAnimation);
	virtual void setupAnimations();

private:
	float _dx, _dy;
	Direction _facing;
};

#endif