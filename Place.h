#pragma once
#include "Field.h"
class Place :
	public Field
{
public:
	Place(SDL_Renderer* passed_renderer, string FilePath, int width, int height, int x_pos, int y_pos);
	~Place();

	virtual string fieldType()=0;
	virtual bool canEnter()=0;
	virtual void affect()=0;
};

