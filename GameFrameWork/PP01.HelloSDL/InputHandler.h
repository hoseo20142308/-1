#pragma once

#include "SDL.h"



class InputHandler
{
public:
	static InputHandler* Instance();
	void update();
	void clean();  // 디바이스 관련 초기화된 부분을 clear 
	bool isKeyDown(SDL_Scancode key);
	const Uint8* m_keystates;

private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
};


typedef InputHandler TheInputHandler;

