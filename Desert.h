#pragma once
#include "Place.h"
class Desert :
	public Place
{
public:
	Desert(SDL_Renderer* passed_renderer, string FilePath, int width, int height, int x_pos, int y_pos);
	~Desert();

	virtual string fieldType();
	virtual bool canEnter();
	virtual void affect();
};

