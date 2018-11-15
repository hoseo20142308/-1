#pragma once

#include <iostream>
#include <SDL_image.h>
#include "SDL.h"
#include "TextureManager.h"
#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "InputHandler.h"
#include <vector>


class Game
{
public:
	~Game() {}

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();
	bool running() { return m_bRunning; }

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	

	static Game* Instance();

private:
	Game() {};
	
	static Game* s_pInstance;

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;

	std::vector<GameObject*> m_gameObjects;

	int m_currentFrame;
	TextureManager* m_textureManager;
	bool m_bRunning;
};

typedef Game TheGame;