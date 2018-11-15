#include "Enemy.h"


Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);

	handleInput();

	m_velocity.normalize();		// 구했던 벡터를 정규화 해주고 * 속도를 일정하게 유지시켜줌

	m_position += m_velocity;	// 객체 현재 위치에 계산한 백터(방향 + 속도)를 더해줌; 

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
void Enemy::clean()
{
}

void Enemy::handleInput()
{
	// 마우스 왼쪽버튼 누를 시 X방향 벡터를 1 증가시켜줌 그냥 이대로는 효과를 볼수 없으며
	// * 효과를 보려면 마우스 위치 받아오는 함수 ↓ 보다 아래에 있어야 함
	if (TheInputHandler::Instance()->getMouseButtonState(TheInputHandler::LEFT))
	{
		m_velocity.setX(1);
	}

	// 매 프레임마다 마우스의 위치를 받아와서
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	// 에너미 오브젝트에서 마우스 위치의 2D벡터를 계산 
	m_velocity = (*vec - m_position) / 100;
}
