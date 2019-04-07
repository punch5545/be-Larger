#pragma once
#include "Rectangles.h"
class Player final : public Rectangles {
public:
	Player();
	~Player() = default;
	void Update();
	void Move(WPARAM wParam);
private:

};