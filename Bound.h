#pragma once
#include "Field.h"
class Bound :
	public Field
{
public:
	Bound(SDL_Renderer* passed_renderer, string FilePath, int width, int height, int x_pos, int y_pos);
	~Bound();

	virtual string fieldType();
	virtual bool canEnter();
	virtual void affect();
};

