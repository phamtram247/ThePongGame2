#ifndef PROCESS_H
#define PROCESS_H
#define _CRT_SECURE_NO_WARNINGS
#include "pad.h"
#include "listitem.h"
#include "fstream"
#include <string>
#include <stdlib.h>
class process :public pad
{
public:
	cPaddle* p;
	cBall* b;
	process();
	~process();
	void reset1(ball & b, pad & player1, pad & player2, int & player1_score, int & player2_score, bool started);
	void reset2(ball & b, pad & you, pad & comp, int & you_score, int & comp_score, bool started);
	void menu();
	void control1();
	void control2();
	void control3(listitem l_item);
	void upscore();
	void input();
	void logicitem(listitem &l_item);
	void checkBallHitPad1(pad &, ball &);
	void checkBallHitPad2(pad &, ball &);
	void setVelCompPad(pad &, ball&);
	void saveGame(string name);
	void result(string name);
	void loadGame(string name);
	void showResult();
};

#endif // !PROCESS_H



