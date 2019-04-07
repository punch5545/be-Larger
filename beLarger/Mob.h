#pragma once
#include "Rectangles.h"

class Mob final : public Rectangles {
public:
	Mob();
	~Mob() = default;
	void Update();
	void Move();
	void setActive(bool isActive);
	auto getActive() { return isActive; }
private:
	DWORD timer = 0;
	void setDir();
	int vertical;
	int horizontal;
};