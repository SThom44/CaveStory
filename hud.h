#pragma once
#ifndef HUD_H
#define HUD_H

#include "sprite.h"
#include "player.h"
#include "graphics.h"

class hud
{
public:
	//default constructor
	hud();
	//custom cosntructor
	hud(Graphics& graphics, Player& player);
	//update function
	void update(int elapsedTime, Player& player);
	//draw function
	void draw(Graphics& graphics);

private:
	Player _player;

	//health hud sprites
	Sprite _healthBarSprite;
	Sprite _healthNumber1;
	Sprite _currentHealthBar;

	//EXP hud sprites
	Sprite _lvWord;
	Sprite _lvNumber;
	Sprite _expBar;

	//Weapon hud sprites
	Sprite _slash;
	Sprite _dashes;
};

#endif