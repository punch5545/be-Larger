#pragma once
class Rectangles {
public:
	Rectangles() = default;
	virtual ~Rectangles() = default;

	auto getSquare() { return square; }
	void setSquare(int left, int top, int right, int bottom);
	void setSquare(RECT rect);

	bool isIntersect(const RECT& player);

	auto getRGB() { return rgb; };
	virtual void setRGB(rgbColor rgb);

	void DrawSquares(HDC hdc);
	virtual void Update() = 0;
protected:
	RECT square;
	HBRUSH curBrush;
	HBRUSH oldBrush;
	rgbColor rgb;

	short ID;

	bool isActive = false;
};