#pragma once

#include "SDL.h"
#include "Vector2D.h"
#include <vector>



class InputHandler
{
public:

	enum mouse_buttons
	{
		LEFT = 0,
		MIDDLE = 1,
		RIGHT = 2
	};

	static InputHandler* Instance();
	void update();
	void clean();  // 디바이스 관련 초기화된 부분을 clear 

	// keyboard button events
	bool isKeyDown(SDL_Scancode key);
	const Uint8* m_keystates;

	// mouse button events
	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();

private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;

	// mouse buttion events								
	std::vector<bool> m_mouseButtonStates;

	// mouse motion event					
	Vector2D* m_mousePosition;

	// event method
	void onMouseMove(SDL_Event event);
	void onMouseButtonDown(SDL_Event event);
	void onMouseButtonUp(SDL_Event event);
	void onKeyDown();
	void onKeyUp();
};


typedef InputHandler TheInputHandler;

