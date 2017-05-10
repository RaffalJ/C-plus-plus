#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Field
{
private:
	SDL_Texture* image;
	SDL_Rect rect;
	SDL_Renderer* renderer;

	bool empty;
	int width;
	int height;
	int x_pos;
	int y_pos;
public:
	Field(SDL_Renderer* passed_renderer, string FilePath,int width,int height,int x_pos,int y_pos);
	~Field();

	void Draw();

	double getXpos();
	double getYpos();

	virtual string fieldType() = 0;
	virtual bool canEnter() = 0;
	virtual void affect() = 0;

	void setEmpty(bool empty);
	bool getEmpty();

};

