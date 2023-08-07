#define SDL_MAIN_HANDLED

#include <iostream>
#include "SDL2/SDL.h"

#include "Game.h"

Game* game;

int main(int argv, char *args[])
{
	game = new Game();
	game->init("GameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 640, false);

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->cleanUp();

	return 0;
}