#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	this->ID = 0;
	this->rgb = { 
		static_cast <unsigned short>(255),
		static_cast <unsigned short>(200),
		static_cast <unsigned short>(200)
	};
	this->square.left = 800;
	this->square.top = 420;
	this->square.right = 980;
	this->square.bottom = 600;
}

void Player::Move(WPARAM wParam)
{

}


void Player::Update()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		square.top -= 10;
		square.bottom -= 10;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		square.top += 10;
		square.bottom += 10;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		square.left -= 10;
		square.right -= 10;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		square.left += 10;
		square.right += 10;
	}
}
