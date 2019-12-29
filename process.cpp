#include "process.h"



process::process()
{
}


process::~process()
{
}

void process::reset1(ball & b, pad & player1, pad & player2, int & player1_score, int & player2_score, bool started)
{
	//đưa pad về vị trí ban đầu
	player1.resetPad();
	player2.resetPad();
	//đưa bóng về ví trí ban đầu
	b.resetBall();
	//cung cấp lại tốc độ cảu quả bóng
	b.velocityBall();
	//trò chơi bắt đầu
	started = false;
	//thêm bảng điểm
	COORD coord;
	coord.X = 0;
	coord.Y = height;
	SetConsoleCursorPosition(hOut, coord);
	SetConsoleTextAttribute(hOut, 13);
	cout << "\n    Player 1 score: " << player1_score << "\t\tPlayer 2 score: " << player2_score << '\n';
}

void process::reset2(ball & b, pad & you, pad & comp, int & you_score, int & comp_score, bool started)
{
	//đưa pad về vị trí ban đầu
	you.resetPad();
	comp.resetPad();
	//đưa bóng về ví trí ban đầu
	b.resetBall();
	//cung cấp lại tốc độ cảu quả bóng
	b.velocityBall();
	//trò chơi bắt đầu
	started = false;
	//thêm bảng điểm
	COORD coord;
	coord.X = 0;
	coord.Y = height;
	SetConsoleCursorPosition(hOut, coord);
	SetConsoleTextAttribute(hOut, 13);
	cout << "\n    Your score: " << you_score << "\t\tComputer score: " << comp_score << '\n';
}

void process::menu()
{
	//thêm menu
	bool choose = true;
	while (choose == true) {
		COORD p1;
		p1.X = int(width / 2 - 15);
		p1.Y = int(height / 2 - 3);
		SetConsoleCursorPosition(hOut, p1);
		SetConsoleTextAttribute(hOut, 8);
		cout << "PRESS 1: DOUBLE PLAYER MODE\n";
		COORD p2;
		p2.X = int(width / 2 - 15);
		p2.Y = int(height / 2 + 3);
		SetConsoleCursorPosition(hOut, p2);
		SetConsoleTextAttribute(hOut, 8);
		cout << "PRESS 2: COMPUTER MODE\n";
		gotoXY(width / 2 - 15, height / 2 + 9);
		TextColor(8);
		cout << "PRESS 3: ITEM MODE\n";
		gotoXY(width / 2 - 15, height / 2 + 15);
		TextColor(8);
		cout << "PRESS 4: LOAD GAME";
		gotoXY(width / 2 - 15, height / 2 - 9);
		TextColor(8);
		cout << "PRESS 5: RESULT";
		if (GetAsyncKeyState(53))
		{
			gotoXY(width / 2 - 15, height / 2 - 3);
			cout << "                                              ";
			gotoXY(width / 2 - 15, height / 2 + 3);
			cout << "                                              ";
			gotoXY(width / 2 - 15, height / 2 + 9);
			cout << "                                              ";
			gotoXY(width / 2 - 15, height / 2 - 9);
			cout << "                                              ";
			gotoXY(width / 2 - 15, height / 2 + 15);
			cout << "                                              ";
			choose = false;
			showResult();
		}
		if (GetAsyncKeyState(52))
		{
			gotoXY(width / 2 - 15, height / 2 - 3);
			cout << "                                              ";
			gotoXY(width / 2 - 15, height / 2 + 3);
			cout << "                                              ";
			gotoXY(width / 2 - 15, height / 2 + 9);
			cout << "                                              ";
			gotoXY(width / 2 - 15, height / 2 - 9);
			cout << "                                              ";
			gotoXY(width / 2 - 15, height / 2 + 15);
			cout << "                                              ";
			choose = false;
			gotoXY(width / 2 - 15, height / 2 - 3);
			cout << "INPUT YOUR NAME";
			string name;
			gotoXY(width / 2 - 15, height / 2 - 2);
			cin >> name;
			loadGame(name);
			gotoXY(width / 2 - 15, height / 2 - 3);
			cout << "                 ";
			gotoXY(width / 2 - 15, height / 2 - 2);
			cout << "                ";
			listitem li;
		item2:li.createitem(26);
			li.drawitem();

			endDrawBorder3();
			control3(li);

			gotoXY(width / 2 - 6, height / 2);
			cout << "ARE YOU CONTINUE?";
			gotoXY(width / 2 - 6, height / 2 + 1);
			cout << "1.YES  ||  0.NO";
			int o;
			cin >> o;
			if (o == 1)
			{
				gotoXY(width / 2 - 6, height / 2);
				cout << "                 ";
				gotoXY(width / 2 - 6, height / 2 + 1);
				cout << "                ";
				goto item2;
			}
			else
			{
				string name;
				gotoXY(width / 2 - 6, height / 2);
				cout << "                 ";
				gotoXY(width / 2 - 6, height / 2 + 1);
				cout << "                ";
				gotoXY(width / 2 - 6, height / 2);
				cout << "INPUT YOUR NAME";
				gotoXY(width / 2 - 6, height / 2 + 1);
				cin >> name;
				saveGame(name);
			}


		}
		//Xử lý khi người dùng chọn chế độ chơi thứ nhất
		if (GetAsyncKeyState(49)) {
			//xóa menu
			COORD p1;
			p1.X = int(width / 2 - 15);
			p1.Y = int(height / 2 + 3);
			SetConsoleCursorPosition(hOut, p1);
			cout << "                                                ";
			 
			COORD p2;
			p2.X = int(width / 2 - 15);
			p2.Y = int(height / 2 - 3);
			SetConsoleCursorPosition(hOut, p2);
			cout << "                                                ";
			gotoXY(width / 2 - 15, height / 2 + 9);
			cout << "                                              ";
			gotoXY(width / 2 - 15, height / 2 - 9);
			cout << "                                                 ";
			gotoXY(width / 2 - 15, height / 2 + 15);
			cout << "                                                ";
			//thoát khỏi menu
			choose = false;
			//vẽ khung chế độ thứ nhất
			endDrawBorder1();
			//xử lý chế độ chơi thứ nhất
			control1();
		}

		if (GetAsyncKeyState(50)) {
			//xóa menu
			COORD p1;
			p1.X = int(width / 2 - 15);
			p1.Y = int(height / 2 + 3);
			SetConsoleCursorPosition(hOut, p1);
			cout << "                                                ";

			COORD p2;
			p2.X = int(width / 2 - 15);
			p2.Y = int(height / 2 - 3);
			SetConsoleCursorPosition(hOut, p2);
			cout << "                                                ";
			gotoXY(width / 2 - 15, height / 2 + 9);
			cout << "                                              ";
			gotoXY(width / 2 - 15, height / 2 - 9);
			cout << "                                                 ";
			gotoXY(width / 2 - 15, height / 2 + 15);
			cout << "                                                ";
			//thoát khỏi menu
			choose = false;
			//vẽ khung chế độ thứ hai
			endDrawBorder2();
			//xử lý chế độ chơi thứ hai
			control2();
		}

		if (GetAsyncKeyState(51))
		{
			gotoXY(width / 2 - 15, height / 2 - 3);
			cout << "                                              ";
			gotoXY(width / 2 - 15, height / 2 + 3);
			cout << "                                              ";
			gotoXY(width / 2 - 15, height / 2 + 9);
			cout << "                                              ";
			gotoXY(width / 2 - 15, height / 2 - 9);
			cout << "                                              ";
			gotoXY(width / 2 - 15, height / 2 + 15);
			cout << "                                              ";
			choose = false;
			listitem li;
			item:li.createitem(26);
			li.drawitem();
			
			endDrawBorder3();
			control3(li);
			if (b->fgetY() == p->fgetY())
				return;
			gotoXY(width / 2 - 6, height / 2);
			cout << "ARE YOU CONTINUE?";
			gotoXY(width / 2 - 6, height / 2 + 1);
			cout << "1.YES  ||  0.NO";
			int o;
			gotoXY(width / 2 - 6, height / 2 + 2);
			cin >> o;
			if (o == 1)
			{
				gotoXY(width / 2 - 6, height / 2);
				cout << "                 ";
				gotoXY(width / 2 - 6, height / 2 + 1);
				cout << "                ";
				goto item;
			}
			else
			{
				string name;
				gotoXY(width / 2 - 6, height / 2);
				cout << "                 ";
				gotoXY(width / 2 - 6, height / 2 + 1);
				cout << "                ";
				gotoXY(width / 2 - 6, height / 2);
				cout << "INPUT YOUR NAME";
				gotoXY(width / 2 - 6, height / 2 + 1);
				cin >> name;
				saveGame(name);
			}
			
		}
		
		

	}

}

void process::control1()
{
	process MODE1;
	//thêm pad và bóng
	pad player1(width / 2, height - 2);
	pad player2(width / 2, 2);
	ball b(width / 2 - 1, height / 2);
	//cung cấp vận tốc cho trái bóng
	b.velocityBall();
	bool started = false;
	while (true) {
		if (started) {
			//người chơi di chuyển pad
			player1.controlPad1();
			player2.controlPad2();
			//thêm giới hạn của pad( dừng lại khi đụng tường)
			player1.addPlayerBoundaries();
			player2.addPlayerBoundaries();
			//giữ cho trái bóng không di chuyển quá nhanh
			b.controlMaxSpeed();
			//thay đổi vị trí của trái bóng theo vận tốc của nó
			b.setVelBall();
			// kiểm tra và xử lý khi bóng chạm pad của người chơi thứ nhất
			MODE1.checkBallHitPad1(player1, b);
			// kiểm tra và xử lý khi bóng chạm pad của người chơi thứ hai
			MODE1.checkBallHitPad2(player2, b);
			//xử lý khi có người chơi giành chiến thắng và reset về các vị trí ban đầu
			if (b.checkPlayerWin() == 1) {
				++player2_score;
				reset1(b, player1, player2, player1_score, player2_score, started);
			}
			else if (b.checkPlayerWin() == 2) {
				++player1_score;
				reset1(b, player1, player2, player1_score, player2_score, started);
			}
			//xử lý khi bóng chạm tường
			b.checkBallHitWall();
		}
		else {
			//chờ người chơi bắt đầu trận đấu( bấm "space" để bắt đầu)
			COORD p;
			p.X = int(width / 2 - 16);
			p.Y = int(height / 1.5f);
			SetConsoleCursorPosition(hOut, p);
			SetConsoleTextAttribute(hOut, 11);
			cout << "Press the space bar to start . .";
			if (GetAsyncKeyState(VK_SPACE)) {
				COORD p;
				p.X = int(width / 2 - 16);
				p.Y = int(height / 1.5f);
				SetConsoleCursorPosition(hOut, p);
				cout << "                                ";
				started = true;
			}
		}
		// vẽ pad và ball của người chơi
		player1.drawPad();
		player2.drawPad();
		b.drawBall();
		// tốc độ xuất ra màn hình
		Sleep(delay);
	}
}

void process::control2()
{
	process MODE2;
	//thêm pad và bóng
	pad you(width / 2, height - 2);
	pad comp(width / 2, 2);
	ball b(width / 2 - 1, height / 2);
	//cung cấp ận tốc cho trái bóng
	b.velocityBall();
	bool started = false;
	while (true) {
		if (started) {
			//người chơi di chuyển pad
			you.controlPad1();
			// pad của computer tự di chuyển theo trái bóng
			MODE2.setVelCompPad(comp, b);
			//thêm giới hạn của pad( dừng lại khi đụng tường)
			you.addPlayerBoundaries();
			comp.addPlayerBoundaries();
			//giữ cho trái bóng không di chuyển quá nhanh
			b.controlMaxSpeed();
			//thay đổi vị trí của trái bóng theo vận tốc của nó
			b.setVelBall();
			// kiểm tra và xử lý khi bóng chạm pad của người chơi 
			MODE2.checkBallHitPad1(you, b);
			// kiểm tra và xử lý khi bóng chạm pad của computer
			MODE2.checkBallHitPad2(comp, b);
			//xử lý khi có người chơi giành chiến thắng và reset về các vị trí ban đầu
			if (b.checkPlayerWin() == 1) {
				++player2_score;
				reset2(b, you, comp, player1_score, player2_score, started);
			}
			else if (b.checkPlayerWin() == 2) {
				++player1_score;
				reset2(b, you, comp, player1_score, player2_score, started);
			}
			//xử lý khi bóng chạm tường
			b.checkBallHitWall();
		}
		else {
			//chờ người chơi bắt đầu trận đấu( bấm "space" để bắt đầu)
			COORD p;
			p.X = int(width / 2 - 16);
			p.Y = int(height / 1.5f);
			SetConsoleCursorPosition(hOut, p);
			SetConsoleTextAttribute(hOut, 11);
			cout << "Press the space bar to start . .";
			if (GetAsyncKeyState(VK_SPACE)) {
				COORD p;
				p.X = int(width / 2 - 16);
				p.Y = int(height / 1.5f);
				SetConsoleCursorPosition(hOut, p);
				cout << "                                ";
				started = true;
			}
		}
		// Draw all objects
		you.drawPad();
		comp.drawPad();
		b.drawBall();
		// Delay
		Sleep(delay);
	}
}

void process::control3(listitem l_item)
{
	b = new cBall(width / 2 + 1, height - 3);
	process MODE3;
	
	bool win = false;
	bool start = false;
	do
	{
		if (start == true)
		{
			logicitem(l_item);
			input();
			if (l_item.li.empty() == true)
				win = true;
			else if (b->fgetY() == p->fgetY())
				return;
		}
		else
		{
			gotoXY(width / 2 - 16, height / 2);
			TextColor(8);
			cout << "Press the SPACE to start game";
			if (GetAsyncKeyState(VK_SPACE))
			{
				gotoXY(width / 2 - 16, height / 2);
				cout << "                             ";
				p = new cPaddle(width / 2, height - 2);
				drawPad2();
				fdrawball();
				start = true;
			}
		}
	} while (win == false);
}

void process::upscore()
{
	item_score = item_score + 10;
	gotoXY(1, height + 1);
	TextColor(8);
	cout << "Your score: " << item_score;
}

void process::input()
{
	int px = p->fgetX();
	int py = p->fgetY();
	if (_kbhit()) //Phat hien nguoi dung nhap tu ban phim
	{
		char current = _getch();
		if (current == 'a')
			if (px > 1)
				p->fmoveLeft();
		if (current == 'd')
			if (px + 10 < width)
				p->fmoveRight();
		
	}
}

void process::logicitem(listitem &l_item)
{
	b->fMove();
	//input();
	int ballx = b->fgetX();
	int bally = b->fgetY();
	int playerx = p->fgetX();
	int playery = p->fgetY();
	//Nguoi choi
	if (bally == playery - 1)
	{
		if ((ballx == playerx - 1) && (b->fgetDirection() == DOWNRIGHT))
		{
			b->fchangeDirection(UPLEFT);
			//break;
		}

		else if ((ballx == playerx + 10) && (b->fgetDirection() == DOWNLEFT))
		{
			b->fchangeDirection(UPRIGHT);
			//break;
		}
		for (int k = 0; k < 10; k++)
		{
			if (ballx == playerx + k)
			{
				if (b->fgetDirection() == DOWN)
				{
					if (ballx <= playerx + 5)
					{
						b->fchangeDirection(UPLEFT);
						break;
					}
					else
					{
						b->fchangeDirection(UPRIGHT);
						break;
					}
				}
				else if (b->fgetDirection() == DOWNLEFT)
				{
					b->fchangeDirection(UPLEFT);
					break;
				}
				else if (b->fgetDirection() == DOWNRIGHT)
				{
					b->fchangeDirection(UPRIGHT);
					break;
				}
			}
		}
		b->fupSpeed();
	}

	list<item>::iterator i;
	for (i = l_item.li.begin(); i != l_item.li.end(); i++)
	{
		
		if (ballx == 1 && bally == 1 && b->fgetDirection() == UPLEFT)
		{
			b->fchangeDirection(DOWNRIGHT);
		}

		else if (ballx == width - 2 && bally == 1 && b->fgetDirection() == UPRIGHT)
		{
			b->fchangeDirection(DOWNLEFT);
		}

		//Tuong trai
		else if (ballx == 1)
		{
			if (b->fgetDirection() == DOWNLEFT)
			{
				b->fchangeDirection(DOWNRIGHT);
				break;
			}
			else if (b->fgetDirection() == UPLEFT)
			{
				b->fchangeDirection(UPRIGHT);
				break;
			}
		}

		//Tuong phai
		else if (ballx == width - 3)
		{
			if (b->fgetDirection() == DOWNRIGHT)
			{
				b->fchangeDirection(DOWNLEFT);
				break;
			}
			else if (b->fgetDirection() == UPRIGHT)
			{
				b->fchangeDirection(UPLEFT);
				break;
			}
		}
		//Tuong tren
		else if (bally == 1)
		{
			if (b->fgetDirection() == UPRIGHT)
			{
				b->fchangeDirection(DOWNRIGHT);
				break;
			}
			else if (b->fgetDirection() == UPLEFT)
			{
				b->fchangeDirection(DOWNLEFT);
				break;
			}
			else if (b->fgetDirection() == UP)
			{
				b->fchangeDirection(DOWN);
				break;
			}
		}

		//Phia tren item
		
		else if (bally == i->gety() - 1)
		{
			if (ballx == i->getx1() || ballx == i->getx2() || ballx == i->getx3() || ballx == i->getx4())
			{
				if (b->fgetDirection() == DOWN)
				{
					b->fchangeDirection(UP);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
				else if (b->fgetDirection() == DOWNLEFT)
				{
					b->fchangeDirection(UPLEFT);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
				else if (b->fgetDirection() == DOWNRIGHT)
				{
					b->fchangeDirection(UPRIGHT);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
			}
			else if ((ballx == i->getx1() - 1) && (b->fgetDirection() == DOWNRIGHT))
			{
				b->fchangeDirection(UPLEFT);
				l_item.deleteitem(*i);
				upscore();
				break;
			}
			else if ((ballx == i->getx4() + 1) && (b->fgetDirection() == DOWNLEFT))
			{
				b->fchangeDirection(UPRIGHT);
				l_item.deleteitem(*i);
				upscore();
				break;
			}
		}

		//Phia duoi item
		else if (bally == i->gety() + 1)
		{
			if (ballx == i->getx1() || ballx == i->getx2() || ballx == i->getx3() || ballx == i->getx4())
			{
				if (b->fgetDirection() == UP)
				{
					b->fchangeDirection(DOWN);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
				else if (b->fgetDirection() == UPLEFT)
				{
					b->fchangeDirection(DOWNLEFT);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
				else if (b->fgetDirection() == UPRIGHT)
				{
					b->fchangeDirection(DOWNRIGHT);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
			}
			else if ((ballx == i->getx1() - 1) && (b->fgetDirection() == UPRIGHT))
			{
				b->fchangeDirection(DOWNLEFT);
				l_item.deleteitem(*i);
				upscore();
				break;
			}
			else if ((ballx == i->getx4() + 1) && (b->fgetDirection() == UPLEFT))
			{
				b->fchangeDirection(DOWNRIGHT);
				l_item.deleteitem(*i);
				upscore();
				break;
			}
		}

		//Ben trai item
		else if (ballx == i->getx1() - 1)
		{
			if (bally == i->gety())
			{
				if (b->fgetDirection() == UPRIGHT)
				{
					b->fchangeDirection(UPLEFT);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
				else if (b->fgetDirection() == DOWNRIGHT)
				{
					b->fchangeDirection(DOWNLEFT);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
			}
		}

		//Ben phai item
		else if (ballx == i->getx4() + 1)
		{
			if (bally == i->gety())
			{
				if (b->fgetDirection() == UPLEFT)
				{
					b->fchangeDirection(UPRIGHT);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
				else if (b->fgetDirection() == DOWNLEFT)
				{
					b->fchangeDirection(DOWNRIGHT);
					l_item.deleteitem(*i);
					upscore();
					break;
				}
			}
		}
	}
	if (l_item.li.empty() == true)
	{
		gotoXY(ballx, bally);
		cout << " ";
		gotoXY(playerx, playery);
		cout << "          ";
	}

	if (bally == playery)
	{
		string name;
		gotoXY(ballx, bally);
		cout << " ";
		gotoXY(playerx, playery);
		cout << "          ";
		gotoXY(width / 2 - 6, height / 2);
		cout << "GAME OVER";
		gotoXY(width / 2 - 6, height / 2 + 1);
		cout << "INPUT YOUR NAME";
		gotoXY(width / 2 - 6, height / 2 + 2);
		cin >> name;
		result(name);
		return;
	}
	


}

void process::checkBallHitPad1(pad &X, ball &A)
{
	if (int(A.by) >= int(X.py - 1) && int(A.by) <= int(X.py + 1)) {
		if (int(A.bx) > int(X.px - size) && int(A.bx) < int(X.px + size)) {
			A.velY *= (-1.1);
			A.velX += float(A.bx - X.px) / 3;
			A.by = X.py - 1;
		}
	}
}  //xử lý khi trái bóng chạm pad phía dưới sân đấu

void process::checkBallHitPad2(pad &X, ball &A)
{
	if (int(A.by) <= int(X.py + 1) && int(A.by) >= int(X.py - 1)) {
		if (int(A.bx) > int(X.px - size) && int(A.bx) < int(X.px + size)) {
			A.velY *= (-1.1);
			A.velX += float(A.bx - X.px) / 3;
			A.by = X.py + 1;
		}
	}
}  //xử lý khi trái bóng chạm pad phía trên sân đấu

void process::setVelCompPad(pad &X, ball &A)
{
	X.velPX = 0;
	X.velX -= float(X.px - A.bx) / 10.0f;
	X.velX *= 0.85f;
	X.px += X.velX;
}  //cung cấp tốc độ cho thanh pad của máy phụ thuộc vào vận tốc trái bóng

void process::saveGame(string name)
{
	char temp[10];
	char temp2[10];
	_itoa(item_score, temp, 10);
	_itoa(b->fgetSpeed(), temp2, 10);
	fstream f;
	f.open("SaveGame.txt", ios::app);
	f << name;
	f << "\t";
	f << temp;
	f << "\t";
	f << temp2;
	f << "\n";
	f.close();
}

void process::result(string name)
{
	char temp[10];
	_itoa(item_score, temp, 10);
	fstream f;
	f.open("Result.txt", ios::app);
	f << name;
	f << "\t";
	f << temp;
	f << "\n";
	f.close();
}

void process::loadGame(string name)
{
	fstream f;
	f.open("SaveGame.txt");
	if (!f)
	{
		gotoXY(width / 2 - 6, height / 2);
		cout << "Khong mo duoc file";
	}
	while (!f.eof())
	{
		string name2, temp, temp2;
		getline(f, name2, '\t');
		if (name2 == "") break;
		getline(f, temp, '\t');
		getline(f, temp2, '\n');
		int score = atoi(temp.c_str());
		int Speed = atoi(temp2.c_str());
		if (name2 == name)
		{
			item_score = score;
			b->fsetSpeed(Speed);
		}
		
	}
}

void process::showResult()
{
	fstream f;
	f.open("Result.txt");
	if (!f)
	{
		gotoXY(width / 2 - 6, height / 2);
		cout << "Khong mo duoc file";
	}
	int count = 1;
	while (!f.eof())
	{
		string name, temp;
		getline(f, name, '\t');
		if (name == "") break;
		getline(f, temp, '\n');
		int score = atoi(temp.c_str());
		gotoXY(width / 2 - 6, 3);
		cout << "RESULT";
		gotoXY(width / 2 - 6, 3 + count);
		cout << "TOP " << count << ": " << name << "    " << score;
		count++;
		if (count == 6)
			break;
	}
}





