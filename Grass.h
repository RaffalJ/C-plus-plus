#pragma once
#include "Place.h"
class Grass :
	public Place
{
public:
	Grass(SDL_Renderer* passed_renderer, string FilePath, int width, int height, int x_pos, int y_pos);
	~Grass();

	virtual string fieldType();
	virtual bool canEnter();
	virtual void affect();
};

