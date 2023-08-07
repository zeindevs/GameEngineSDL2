#include <iostream>
#include "Game.h"
#include "GameObject.h"
#include "TextureManager.h"

SDL_Renderer* Game::renderer = nullptr;

GameObject* player;
GameObject* enemy;

Game::Game()
{

}

Game::~Game()
{

}


void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen) 
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystem initialized!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window) 
			std::cout << "Window created!" << std::endl;

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255,255,255,255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	} else {
		isRunning = false;
	}


	player = new GameObject("res/textures/player.png", 0, 0);
	enemy = new GameObject("res/textures/enemy.png", 50, 50);

}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	player->Update();
	enemy->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);	
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);
}

void Game::cleanUp()
{	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}