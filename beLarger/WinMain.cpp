#include "stdafx.h"
#include "Player.h"
#include "Mob.h"
using namespace std;


Player* player = new Player();
Mob* mob = new Mob[7];

int mobcount = 7;

LRESULT CALLBACK WndProc
(
	HWND hwnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam

);

int APIENTRY WinMain
(
	HINSTANCE hinstance,
	HINSTANCE previnstance,
	LPSTR ipszCmdaram,
	int nCmdShow
)
{
	WNDCLASS wndclass; //설계단계
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	wndclass.hCursor = LoadIcon(nullptr, IDC_HAND);
	wndclass.hIcon = LoadIcon(nullptr, IDI_ERROR);
	wndclass.hInstance = hinstance;
	wndclass.lpfnWndProc = static_cast<WNDPROC> (WndProc);
	wndclass.lpszClassName = L"BeLarger";
	wndclass.lpszMenuName = nullptr;
	wndclass.style = CS_HREDRAW | CS_VREDRAW; 
	RegisterClass(&wndclass);

	HWND hwnd = CreateWindow
	(
		L"BeLarger",
		L"Be Larger",
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		WINDOWS_WIDTH,
		WINDOWS_HEIGHT,
		nullptr,
		nullptr,
		hinstance,
		nullptr
	);

	ShowWindow(hwnd, nCmdShow);

	MSG message;
	ZeroMemory(&message, sizeof(MSG));

	while (true)
	{
		if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
				break;

			TranslateMessage(&message);			 //문자키들을 어떤키를 눌렀는지 번역 (메시지 번역)
			DispatchMessage(&message);			 //message로 보내는역활
		}
	}

	DestroyWindow(hwnd);

	UnregisterClass(L"BeLarger", hinstance);
	return message.wParam;

}


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	player->Update();
	switch (message)
	{
	case WM_KEYDOWN:
		InvalidateRect(hwnd, nullptr, TRUE);
		if (mobcount <= 0) {
			if (MessageBox(hwnd, L"CLEAR!", L"Notice", MB_ICONINFORMATION))
				PostQuitMessage(0);
		}
		break;

	case WM_PAINT:
	{

		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		player->DrawSquares(hdc);
		RECT pSquare = player->getSquare();
		for (int i = 0; i < 7; i++) {
			if (mob[i].getActive()) {
				mob[i].Update();
				mob[i].DrawSquares(hdc);
				if (mob[i].isIntersect(player->getSquare())) {
					mob[i].setActive(false);
					player->setRGB(mob[i].getRGB());
					player->setSquare(
						pSquare.left	- 20,
						pSquare.top		- 20,
						pSquare.right	+ 20,
						pSquare.bottom	+ 20);
					mobcount--;
				}
			}			
		}

		EndPaint(hwnd, &ps);
	}
	break;

	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	for (int i = 0; i < 7; i++)
		mob[i].Update();
	return 0;
}