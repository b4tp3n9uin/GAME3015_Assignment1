#include "Player.h"
// #include "Game.h"


Player::Player()
{
}

Player::~Player()
{
}

void Player::Init()
{
	
}

// player update
void Player::Update(const GameTimer& gt)
{
    OnKeyboardInput(gt);
}


void Player::Draw()
{
	// EntityRenderItem->World = getTransform();
	// EntityRenderItem->NumFramesDirty++;
}



// player input
void Player::OnKeyboardInput(const GameTimer& gt)
{
	m_PlayerSpeed = 0.02f;

	if (GetAsyncKeyState('D') & 0x8000)
	{
		Position.x += m_PlayerSpeed;
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		Position.z -= m_PlayerSpeed;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		Position.x -= m_PlayerSpeed;
	}

	if (GetAsyncKeyState('W') & 0x8000)
	{
		Position.z += m_PlayerSpeed;
	}
}