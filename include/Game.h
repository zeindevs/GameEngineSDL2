#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Game
{
private:
	SDL_Window* window;

	bool isRunning = false;

public:
	Game();
	~Game();

public:
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void cleanUp();

	bool running() { return isRunning; };

public:
	static SDL_Renderer* renderer;
};