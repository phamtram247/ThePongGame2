#ifndef PAH_H
#define PAH_H
#include "ball.h"
class pad :public ball
{
protected:
	float padX, padY;
	int size = 4;
public:
	float px, py, velPX;
	pad();
	~pad();
	pad(float cx, float cy);
	void drawPad();
	void drawPad2();
	void controlPadItem();
	void controlPad1();
	void controlPad2();
	void addPlayerBoundaries();
	void resetPad();
};

class cPaddle // Tao class cai thanh dung de do bong
{
private:
	int x, y; // Toa do thanh
	int originalX, originalY; // Toa do ban dau
public:
	cPaddle(); // Ham khoi tao Pad
	cPaddle(int posX, int posY); // Ham khoi tao Pad
	void fReset(); // Reset thanh choi 
	void fmoveLeft(); // Lam cho thanh choi di chuyen len tren
	void fmoveRight(); // Lam cho thanh choi di chuyen xuong duoi
	int fgetX(); // Ham nhan lai gia tri hoanh do cua Pad
	int fgetY(); // Ham nhan lai gia tri tung do cua Pad
};


#endif // !PAH_H


