
#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <string.h>

#include "Player.h"

#include "Board.h"

using namespace std;

class Sorcerer :public Player
{
private:
	bool MoveRight;
	bool MoveLeft;
	bool MoveUp;
	bool MoveDown;
	int speed;

	int timeCheck;
	int timeCheck2;

	bool MoveFRight;
	bool MoveFLeft;
	bool MoveFUp;
	bool MoveFDown;

	bool fr1;
	bool fr2;

	bool fl1;
	bool fl2;

	bool fd1;
	bool fd2;

	bool fu1;
	bool fu2;

	bool change;
public:
	Sorcerer(SDL_Renderer* passed_renderer, string fimg_front, string fimg_back, string fimg_left, string fimg_right, int x, int y, int w, int h, string  name, double health, double attack);
	~Sorcerer();
	string type();

	void move(SDL_Event* sdl_event, SDL_Renderer* renderer, Sorcerer* sorcerer);
	void field_collision(Sorcerer* sorcerer,Board* board);
};