#include "player.h"

namespace player_constants {
	const float WALK_SPEED = 0.2f;
	const float GRAVITY = 0.002f;
	const float GRAVITY_CAP = 0.8f;
}

//default constructor
Player::Player() {}

//custom constructor
Player::Player(Graphics& graphics, Vector2 spawnPoint) :
	AnimatedSprite(graphics, "MyChar.png", 0, 0, 16, 16, spawnPoint.x, spawnPoint.y, 100),
	_dx(0),
	_dy(0),
	_facing(Direction::RIGHT),
	_grounded(false)
{
	graphics.loadImage("MyChar.png");
	this->setupAnimations();
}

//draw function for AnimatedSprite
void Player::draw(Graphics& graphics) {
	AnimatedSprite::draw(graphics, this->_x, this->_y);
}

//update function for AnimatedSprite
void Player::update(float elapsedTime) {
	this->_x += this->_dx * elapsedTime;
	AnimatedSprite::update(elapsedTime);
}

void Player::moveLeft() {
	this->_dx = -player_constants::WALK_SPEED;
	this->playAnimation("RunLeft");
	this->_facing = Direction::LEFT;
}

void Player::moveRight() {
	this->_dx = player_constants::WALK_SPEED;
	this->playAnimation("RunRight");
	this->_facing = Direction::RIGHT;
}

void Player::stopMoving() {
	this->_dx = 0.0f;
	this->playAnimation(this->_facing == Direction::RIGHT ? "IdleRight" : "IdleLeft");
}

//animations function to signal an animation has finished
void Player::animationDone(string currentAnimation) {

}

//setupAnimations function
void Player::setupAnimations() {
	this->addAnimation(1, 0, 0, "IdleLeft", 16, 16, Vector2(0, 0));
	this->addAnimation(1, 0, 16, "IdleRight", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 0, 16, "RunRight", 16, 16, Vector2(0, 0));
}

void Player::handleTileCollisions(vector<Rectangle>& others) {
	for (int i = 0; i < others.size(); i++) {
		sides::Side collisionSide = Sprite::getCollisionSide(others.at(i));
		if (collisionSide != sides::Side::NONE) {
			switch (collisionSide) {
			case sides::Side::TOP:
				this->_y = others.at(i).getBottom() + 1;
				this->_dy = 0;
				break;
			case sides::Side::BOTTOM:
				this->_y = others.at(i).getTop() - this->_boundingBox.getHeight() - 1;
				this->_dy = 0;
				this->_grounded = true;
				break;
			case sides::Side::LEFT:
				this->_x = others.at(i).getRight() + 1;
				break;
			case sides::Side::RIGHT:
				this->_x = others.at(i).getLeft() - this->_boundingBox.getWidth() - 1;
			}
		}
	}
}

const float Player::getX() const {
	return this->_x;
}
const float Player::getY() const {
	return this->_y;
}