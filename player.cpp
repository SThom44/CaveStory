#include "player.h"

namespace player_constants {
	const float WALK_SPEED = 0.2f;
}

//default constructor
Player::Player() {}

//custom constructor
Player::Player(Graphics& graphics, float x, float y) :
	AnimatedSprite(graphics, "MyChar.png", 0, 0, 16, 16, x, y, 100)
{
	graphics.loadImage("MyChar.png");
	this->setupAnimations();
	_facing = Direction::RIGHT;
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