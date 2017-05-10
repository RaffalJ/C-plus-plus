#pragma once
#include "Field.h"
class Water :
	public Field
{
public:
	Water(SDL_Renderer* passed_renderer, string FilePath, int width, int height, int x_pos, int y_pos);
	~Water();

	virtual string fieldType();
	virtual bool canEnter();
	virtual void affect();
};

