#include "game.h"

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game() {

}

//initialize game loop objects
void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;

	this->_level = Level("map 1", graphics);
	this->_player = Player(graphics, this->_level.getPlayerSpawnpoint());
	this->_hud = hud(graphics, this->_player);

	int LAST_UPDATE_TIME = SDL_GetTicks();

	//start game loop timer
	while (true) {
		input.beginNewFrame();
		//beginning the main game loop
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			}
			if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			if (event.type == SDL_QUIT) {
				return;
			}
		}
		//if key held down is esx, kill window
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}
		//if key is left, move player left
		else if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true) {
			this->_player.moveLeft();
		}
		//if key is right, move player right
		else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true) {
			this->_player.moveRight();
		}

	//if either left or right released, stop player
		if (!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT)) {
			this->_player.stopMoving();
		}

		if (input.isKeyHeld(SDL_SCANCODE_UP) == true) {
			this->_player.lookUp();
		}

		if (input.wasKeyReleased(SDL_SCANCODE_UP) == true) {
			this->_player.stopLookingUp();
		}

		if (input.isKeyHeld(SDL_SCANCODE_DOWN) == true) {
			this->_player.lookDown();
		}

		if (input.wasKeyReleased(SDL_SCANCODE_DOWN) == true) {
			this->_player.stopLookingDown();
		}

		if (input.isKeyHeld(SDL_SCANCODE_Z) == true) {
			this->_player.jump();
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->_graphics = graphics;
		this->update(min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;
		
		this->draw(graphics);
	}
}

//define draw method
void Game::draw(Graphics& graphics) {
	graphics.clear();
	this->_level.draw(graphics);
	this->_player.draw(graphics);
	this->_hud.draw(graphics);
	graphics.flip();
}

//define update method
void Game::update(float elapsedTime){
	this->_level.update(elapsedTime, this->_player);
	this->_player.update(elapsedTime);
	this->_hud.update(elapsedTime, this->_player);

	//Check for collisions
	vector<Rectangle> others;
	if ((others = this->_level.checkTileCollisions(this->_player.getBoundingBox())).size() > 0) {
		this->_player.handleTileCollisions(others);
	}

	vector<slope> otherSlopes;
	if ((otherSlopes = this->_level.checkSlopeCollisions(this->_player.getBoundingBox())).size() > 0) {
		this->_player.handleSlopeCollisions(otherSlopes);
	}

	vector<Door> otherDoors;
	if ((otherDoors = this->_level.checkDoorCollisions(this->_player.getBoundingBox())).size() > 0) {
		this->_player.handleDoorCollisions(otherDoors, this->_level, this-> _graphics);
	}

	vector<Enemy*> otherEnemies;
	if ((otherEnemies = this->_level.checkEnemyCollisions(this->_player.getBoundingBox())).size() > 0) {
		this->_player.handleEnemyCollisions(otherEnemies);
	}
}
