#pragma once
#include "Place.h"
class Road :
	public Place
{
public:
	Road(SDL_Renderer* passed_renderer, string FilePath, int width, int height, int x_pos, int y_pos);
	~Road();

	virtual string fieldType();
	virtual bool canEnter();
	virtual void affect();
};

