﻿#include "pad.h"



pad::pad()
{
}


pad::~pad()
{
}




pad::pad(float cx, float cy)
{
	px = cx;
	py = cy;
	padX = cx;
	padY = cy;
}

void pad::drawPad()
{
	COORD coord;
	coord.X = int(padX) - size;
	coord.Y = int(padY);
	SetConsoleCursorPosition(hOut, coord);
	for (int i = -size; i < size; ++i)
		cout << ' ';
	coord.X = int(px) - size;
	coord.Y = int(py);
	SetConsoleCursorPosition(hOut, coord);
	SetConsoleTextAttribute(hOut, 10);
	for (int i = -size; i < size; ++i)
		cout << '=';
	SetConsoleTextAttribute(hOut, 15);
	padX = px;
	padY = py;
}   //Vẽ thanh pad

void pad::drawPad2()
{
	gotoXY(width / 2, height - 2);
	TextColor(12);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
}

void pad::controlPadItem()
{
	if (GetAsyncKeyState(VK_LEFT)) {
		if (px - 6 <= 0) return;
		else
		{
			gotoXY(px + 3, py);
			cout << "  ";
			px = px - 2;
			gotoXY(px - 5, py);
			TextColor(10);
			cout << "\xDB\xDB";
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT)) {
		if (px + 4 >= width - 3) return;
		else
		{
			gotoXY(px - 5, py);
			cout << "  ";
			px = px + 2;
			gotoXY(px + 3, py);
			TextColor(10);
			cout << "\xDB\xDB";
		}
	}
}

void pad::controlPad1()
{
	if (GetAsyncKeyState(VK_LEFT)) {
		px -= 3;
	}
	else if (GetAsyncKeyState(VK_RIGHT)) {
		px += 3;
	}
}   //điều khiển thanh pad bằng hai phím trái và phải

void pad::controlPad2()
{
	if (GetAsyncKeyState(65)) {
		px -= 3;
	}
	else if (GetAsyncKeyState(68)) {
		px += 3;
	}
}   //điều khiển thanh pad bằng 2 phím "a" và "d"

void pad::addPlayerBoundaries()
{
	if (px < size + 1) {
		px = float(size + 1);
	}
	else if (px > 70 - size - 2) {
		px = float(70 - size - 2);
	}
}   //giới hạn thanh pad( dừng lại nếu chạm tường)

void pad::resetPad()
{
	px = float(70 / 2);
}   //đưa vị trí thanh pad về vị trí ban đầu nếu có người giành chiến thắng





cPaddle::cPaddle()
{
	x = y = 0;
	originalX = originalY = 0;
}

cPaddle::cPaddle(int posX, int posY)
{
	originalX = posX; // Khoi tao gia tri ban dau cua x (do nguoi dung hoac dung ham san co tao ra)
	originalY = posY; // Nhu tren
	x = posX;
	y = posY;
}

void cPaddle::fReset()
{
	x = originalX; // Dua thanh choi ve toa do ban dau
	y = originalY;
}

void cPaddle::fmoveLeft()
{
	gotoXY(x + 8, y);
	cout << "  ";
	x = x - 2; // Di chuyen sang trai giam hoanh do
	gotoXY(x, y);
	TextColor(12);
	cout << "\xDB\xDB";
}

void cPaddle::fmoveRight()
{
	gotoXY(x, y);
	cout << "  ";
	x = x + 2; // Di chuyen sang phai tang hoanh do
	gotoXY(x + 8, y);
	TextColor(12);
	cout << "\xDB\xDB";
}



int cPaddle::fgetX()
{
	return x;
}

int cPaddle::fgetY()
{
	return y;
}







