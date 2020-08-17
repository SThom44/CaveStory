#include "hud.h"

//deafault constructor
hud::hud() {}

//custom constructor
hud::hud(Graphics& graphics, Player& player) {
	this->_player = player;
	this->_healthBarSprite = Sprite(graphics, "Textbox.png", 0, 40, 64, 8, 35, 70);
	this->_healthNumber1 = Sprite(graphics, "Textbox.png", 0, 56, 8, 8, 66, 70);
	this->_currentHealthBar = Sprite(graphics, "Textbox.png", 0, 25, 39, 5, 83, 72);
	this->_lvWord = Sprite(graphics, "Textbox.png", 81, 81, 11, 7, 38, 55);
	this->_lvNumber = Sprite(graphics, "Textbox.png", 0, 56, 8, 8, 66, 52);
	this->_expBar = Sprite(graphics, "Textbox.png", 0, 72, 40, 8, 83, 52);
	this->_slash = Sprite(graphics, "Textbox.png", 72, 48, 8, 8, 100, 36);
	this->_dashes = Sprite(graphics, "Textbox.png", 81, 51, 15, 11, 132, 26);
}

void hud::update(int elapsedTime, Player& player) {
	this->_player = player;
	this->_healthNumber1.setSourceRectX(8 * this->_player.getCurrentHealth());
	//Calculate the width of the healthbar 100% = 39px
	float num = (float)this->_player.getCurrentHealth() / this->_player.getMaxHealth();
	this->_currentHealthBar.setSourceRectW(floor(num * 39));
}

void hud::draw(Graphics& graphics) {
	this->_healthBarSprite.draw(graphics, this->_healthBarSprite.getX(), this->_healthBarSprite.getY());
	this->_healthNumber1.draw(graphics, this->_healthNumber1.getX(), this->_healthNumber1.getY());
	this->_currentHealthBar.draw(graphics, this->_currentHealthBar.getX(), this->_currentHealthBar.getY());
	this->_lvWord.draw(graphics, this->_lvWord.getX(), this->_lvWord.getY());
	this->_lvNumber.draw(graphics, this->_lvNumber.getX(), this->_lvNumber.getY());
	this->_expBar.draw(graphics, this->_expBar.getX(), this->_expBar.getY());
	this->_slash.draw(graphics, this->_slash.getX(), this->_slash.getY());
	this->_dashes.draw(graphics, this->_dashes.getX(), this->_dashes.getY());
}