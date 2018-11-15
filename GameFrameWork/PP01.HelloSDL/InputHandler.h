#pragma once

#include "SDL.h"



class InputHandler
{
public:
	static InputHandler* Instance();
	void update();
	void clean();  // ����̽� ���� �ʱ�ȭ�� �κ��� clear 
	bool isKeyDown(SDL_Scancode key);
	const Uint8* m_keystates;

private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
};


typedef InputHandler TheInputHandler;

