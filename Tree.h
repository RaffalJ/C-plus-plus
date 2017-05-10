#pragma once
#include "Field.h"
class Tree :
	public Field
{
public:
	Tree(SDL_Renderer* passed_renderer, string FilePath, int width, int height, int x_pos, int y_pos);
	~Tree();

	virtual string fieldType();
	virtual bool canEnter();
	virtual void affect();
};

