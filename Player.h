#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


class Player{
private:
	SDL_Texture* image_current;

	SDL_Texture* image_front;
	SDL_Texture* image_back;
	SDL_Texture* image_left;
	SDL_Texture* image_right;

	SDL_Rect rect;
	SDL_Renderer* renderer;

	string name;
	double health;
	double attack;
	double moveSpeed;

	bool MoveRight;
	bool MoveLeft;
	bool MoveUp;
	bool MoveDown;
	int speed;

	int timeCheck;
	int timeCheck2;

	int field_x;
	int field_y;
public:
	Player(SDL_Renderer* passed_renderer, string fimg_front, string fimg_back, string fimg_left, string fimg_right, int x, int y, int w, int h, string name, double health, double attack);
	~Player();

	// SDL functions
	void Draw();
	void setX(int x);
	void setY(int y);
	void setXY(int x, int y);
	int getX();
	int getY();

	SDL_Texture* getCurrentImage();
	SDL_Texture* getFrontImage();
	SDL_Texture* getBackImage();
	SDL_Texture* getLeftImage();
	SDL_Texture* getRightImage();

	void setCurrentImage(SDL_Texture* img);

	// -----------------------

	void setField(int field_x, int field_y);
	double getFieldx();
	double getFieldy();

	// -----------------------
	string getName();
	void setName(string name);

	double getHealth();
	void setHealth(double health);

	double getAttack();
	void setAttack(double attack);

	double getMoveSpeed();
	void setMoveSpeed(double moveSpeed);
};
