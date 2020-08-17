#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "animatedSprite.h"
#include "graphics.h"
#include "globals.h"
#include "slope.h"
#include "door.h"
#include "level.h"
#include "Enemy.h"

using namespace std;

class Player : public AnimatedSprite {
public:
	//default constructor
	Player();

	//custom constructor
	Player(Graphics& graphics, Vector2 spawnPoint);

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
	//make player look up
	void lookUp();
	//make player stop looking up
	void stopLookingUp();
	//make player look down
	void lookDown();
	//make player stop looking down
	void stopLookingDown();
	//make Quote jump
	void jump();

	//override abstract functions in animatedSprite
	virtual void animationDone(string currentAnimation);
	virtual void setupAnimations();
	void handleTileCollisions(vector<Rectangle> & others);
	void handleSlopeCollisions(vector<slope>& others);
	void handleDoorCollisions(vector<Door>& others, Level& level, Graphics& graphics);
	void handleEnemyCollisions(vector<Enemy*>& others);

	const float getX() const;
	const float getY() const;

	//getter functions for max/current health
	const inline int getMaxHealth() {
		return this->_maxHealth;
	}

	const inline int getCurrentHealth() {
		return this->_currentHealth;
	}

	void gainHealth(int amount);
	
private:
	float _dx, _dy;
	Direction _facing;
	bool _grounded;
	bool _lookingUp = false;
	bool _lookingDown = false;
	int _maxHealth;
	int _currentHealth;
};

#endif