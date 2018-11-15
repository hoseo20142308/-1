#include "Game.h"
#include <SDL_image.h>
#include <iostream>

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;

		//SDL_Surface* pTempSurface = IMG_Load("Assets/animate-alpha.png");
		//m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

		//SDL_FreeSurface(pTempSurface);

		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

		if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
		{
			return false;
		}

		//m_textureManager.load("Assets/animate-alpha.png", "animate", m_pRenderer);

		//m_sourceRectangle.w = 128;
		//m_sourceRectangle.h = 82;

		//m_destinationRectangle.x = m_sourceRectangle.x = 0;
		//m_destinationRectangle.y = m_sourceRectangle.y = 0;
		//m_destinationRectangle.w = m_sourceRectangle.w;
		//m_destinationRectangle.h = m_sourceRectangle.h;

		/*m_go = new GameObject();
		m_player = new Player();
		m_enemy = new Enemy();

		m_go->load(100, 100, 128, 82, "animate");
		m_player->load(300, 300, 128, 82, "animate");
		m_enemy->load(0, 0, 128, 82, "animate");

		m_gameObjects.push_back(m_go);
		m_gameObjects.push_back(m_player);
		m_gameObjects.push_back(m_enemy);*/

		m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
		m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
	}
	else
	{
		return false;	// sdl could not initialize
	}



	return true;
}

void Game::render()
{

	// clear the renderer to the draw color
	SDL_RenderClear(m_pRenderer);	// draw color로 render 지우기
									// 원본 사각형과 대상 사각형의 위치와 크기에 따라 화면에 다르게 나타남...
	/*SDL_RenderCopy(m_pRenderer, m_pTexture,
		&m_sourceRectangle, &m_destinationRectangle);*/

	//m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);

	//m_textureManager.drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);

	//TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);
	//TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);

	//m_go.draw(m_pRenderer);
	//m_player.draw(m_pRenderer);

	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	SDL_RenderPresent(m_pRenderer);	// 화면 제시하기
}

void Game::update()
{
	//m_go.update();
	//m_player.update();

	//TheInputHandler::Instance()->update();

	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::quit()
{
	m_bRunning = false;
	SDL_Quit();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
	/*SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}*/
}

Game* Game::Instance()
{
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
}