#include "stdafx.h"
#include "Mob.h"
std::random_device rd;
std::mt19937 randomEngine(rd());

Mob::Mob()
{
	this->isActive = true;
	this->ID = 1;
	this->rgb = {
		(std::uniform_int_distribution<unsigned short>{ 0, 255 }(randomEngine)),
		(std::uniform_int_distribution<unsigned short>{ 0, 255 }(randomEngine)),
		(std::uniform_int_distribution<unsigned short>{ 0, 255 }(randomEngine))
	};
	this->square.left = std::uniform_int_distribution<int>{ 0, WINDOWS_WIDTH - 200 }(randomEngine);
	this->square.right =  square.left + std::uniform_int_distribution<int>{ 0, 200 }(randomEngine);
	this->square.top = std::uniform_int_distribution<int>{ 0, WINDOWS_HEIGHT - 200 }(randomEngine);
	this->square.bottom =  square.top + std::uniform_int_distribution<int>{ 0, 200 }(randomEngine);
}

void Mob::Update()
{
	Move();
}

void Mob::Move()
{
	if (timeGetTime() - timer > 1000)
	{
		//uniform initialization(중괄호 초기화)
		vertical = std::uniform_int_distribution<int>{ -10, 10 }(randomEngine);
		horizontal = std::uniform_int_distribution<int>{ -10, 10 }(randomEngine);
		timer = timeGetTime();
	}
	setDir();
	this->square.left += vertical;
	this->square.right += vertical;
	this->square.top += horizontal;
	this->square.bottom += horizontal;
}

void Mob::setActive(bool isActive)
{
	this->isActive = isActive;
}

void Mob::setDir()
{
	bool vCheck = false;
	vCheck |= square.left	<= 1;
	vCheck |= square.right	>= WINDOWS_WIDTH;

	bool hCheck = false;
	hCheck |= square.top	<= 1;
	hCheck |= square.bottom >= WINDOWS_HEIGHT;

	if (vCheck)
	{
		vertical *= -1;
	}
	if (hCheck)
	{
		horizontal *= -1;
	}
}
