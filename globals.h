#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H

namespace globals {
	//create global variable to handle screen size
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	//create global variable to scale sprites to 2x their size
	const float SPRITE_SCALE = 2.0f;
}

namespace sides {
	enum class Side {
		TOP,
		BOTTOM,
		LEFT,
		RIGHT,
		NONE
	};

	const inline Side getOppositeSide(Side side) {
		return
			side == Side::TOP ? Side::BOTTOM :
			side == Side::BOTTOM ? Side::TOP :
			side == Side::LEFT ? Side::RIGHT :
			side == Side::RIGHT ? Side::LEFT :
			Side::NONE;
	}
}

//Set movement for assets (Mostly Quote)
enum class Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

//define custom data structure called Vector2
struct Vector2 {
	//declare variables
	int x, y;
	//define default constructor
	Vector2() :
		x(0), y(0)
	{}
	//custom constructor for structure
	Vector2(int x, int y) :
		x(x), y(y)
	{}
	//zero version of custom constructor
	Vector2 zero() {
		return Vector2(0, 0);
	}
};

#endif