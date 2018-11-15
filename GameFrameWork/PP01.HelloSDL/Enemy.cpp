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

	m_velocity.normalize();		// ���ߴ� ���͸� ����ȭ ���ְ� * �ӵ��� �����ϰ� ����������

	m_position += m_velocity;	// ��ü ���� ��ġ�� ����� ����(���� + �ӵ�)�� ������; 

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
void Enemy::clean()
{
}

void Enemy::handleInput()
{
	// ���콺 ���ʹ�ư ���� �� X���� ���͸� 1 ���������� �׳� �̴�δ� ȿ���� ���� ������
	// * ȿ���� ������ ���콺 ��ġ �޾ƿ��� �Լ� �� ���� �Ʒ��� �־�� ��
	if (TheInputHandler::Instance()->getMouseButtonState(TheInputHandler::LEFT))
	{
		m_velocity.setX(1);
	}

	// �� �����Ӹ��� ���콺�� ��ġ�� �޾ƿͼ�
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	// ���ʹ� ������Ʈ���� ���콺 ��ġ�� 2D���͸� ��� 
	m_velocity = (*vec - m_position) / 100;
}
