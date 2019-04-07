#include "stdafx.h"
#include "Rectangles.h"

void Rectangles::setSquare(int left, int top, int right, int bottom)
{
	this->square.left = left;
	this->square.top = top;
	this->square.right = right;
	this->square.bottom = bottom;
}

bool Rectangles::isIntersect(const RECT& player)
{
	RECT tempRect;
	tempRect.left	 =	max(square.left,   player.left);
	tempRect.top	 =	max(square.top,	   player.top);
	tempRect.right   =	min(square.right,  player.right);
	tempRect.bottom  =	min(square.bottom, player.bottom);

	bool bCheck = false;
	bCheck |= (tempRect.right - tempRect.left) < 0;
	bCheck |= (tempRect.bottom - tempRect.top) < 0;

	if (bCheck)
	{
		return false;
	}

	this->isActive = false;
	return true;
}


void Rectangles::setRGB(rgbColor rgb)
{
	this->rgb = rgb;
}

void Rectangles::DrawSquares(HDC hdc)
{
		HBRUSH curBrush = CreateSolidBrush(RGB(rgb.R, rgb.G, rgb.B));
		HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject(hdc, curBrush));

		Rectangle(hdc, square.left, square.top, square.right, square.bottom);

		SelectObject(hdc, oldBrush);
		DeleteObject(curBrush);
}