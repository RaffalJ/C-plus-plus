#include "stdafx.h"
#include "Bound.h"


Bound::Bound(SDL_Renderer* passed_renderer, string FilePath, int width, int height, int x_pos, int y_pos)
:Field(passed_renderer, FilePath, width, height, x_pos, y_pos)
{

}

Bound::~Bound(){

}

string Bound::fieldType(){
	return "Bound";
}

bool Bound::canEnter(){
	return false;
}

void Bound::affect(){

}

