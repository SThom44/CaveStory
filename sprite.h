#pragma once
#ifndef SPRITE_H
#define SPRTE_H

#include "graphics.h"
#include "globals.h"
#include "Rectangle.h"
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

	//getter function for bounding box
	const Rectangle getBoundingBox() const;

	//getter function to figure out colliding sides
	const sides::Side getCollisionSide(Rectangle& other) const;

	//getter functions to getX and getYof sprite box on spritesheet
	const inline float getX() const {
		return this->_x;
	}

	const inline float getY() const {
		return this->_y;
	}

	//functions to set the source points, width
	//and height on the spritesheet and window
	void setSourceRectX(int value);
	void setSourceRectY(int value);
	void setSourceRectH(int value);
	void setSourceRectW(int value);

protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;
	Rectangle _boundingBox;
	float _x, _y;

private:
	
};

#endif