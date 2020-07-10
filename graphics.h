#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "globals.h"
#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

//create a graphics class
class Graphics {

//public methods are available to all parts of the application.
public:
	//graphics object constructor and destructor
	Graphics();
	~Graphics();

	//loads image file to store in the _spriteSheets map.
	SDL_Surface* loadImage(const string &filePath);

	//overlaps texture pulled from sprite sheet onto teh screen.
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	//push render to screen
	void flip();

	//clears screen
	void clear();

	SDL_Renderer* getRenderer() const;

//private methods are available only to the class or any subclass derived fro that class
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	map<string, SDL_Surface*> _spriteSheets;
};

#endif