#include "sprite.h"

//default constructor
Sprite::Sprite() {}

//custom constructor.  create local variables.
Sprite::Sprite(Graphics& graphics, const string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) :
	_x(posX),
	_y(posY)

{
	this->_sourceRect.x = sourceX;
	this->_sourceRect.y = sourceY;
	this->_sourceRect.w = width;
	this->_sourceRect.h = height;

	//If image cannot be found, give error message, otherwise create the texture.
	this->_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
	if (this->_spriteSheet == NULL) {
		printf("\nError: Unable to load image\n");
	}
}

Sprite::~Sprite() {}

//update function
void Sprite::update() {}

//draw the image to screen
void Sprite::draw(Graphics& graphics, int x, int y) {
	SDL_Rect destinationRectangle = { x, y, this->_sourceRect.w * globals::SPRITE_SCALE, this->_sourceRect.h * globals::SPRITE_SCALE };
	graphics.blitSurface(this->_spriteSheet, &this->_sourceRect, &destinationRectangle);
}

