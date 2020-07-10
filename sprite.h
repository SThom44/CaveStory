#pragma once
#ifndef SPRITE_H
#define SPRTE_H

#include "graphics.h"
#include "globals.h"
#include <SDL.h>
#include <string>

using namespace std;

class Graphics;

class Sprite {
public:
	//default constructor NOT USED
	Sprite();
	//custom constructor.  Grabs spritesheet asset and assings it a specific rectangle.
	Sprite(Graphics& grpahics, const string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);

	//get rid of derived sprite objects
	virtual ~Sprite();

	//update and clear specific sprite objects
	virtual void update();

	//draw sprite to specific location
	void draw(Graphics& graphics, int x, int y);

protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;
	float _x, _y;

private:
	
};

#endif