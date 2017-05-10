#include "stdafx.h"
#include "Water.h"


Water::Water(SDL_Renderer* passed_renderer, string FilePath, int width, int height, int x_pos, int y_pos)
:Field( passed_renderer,FilePath,width, height, x_pos, y_pos)
{
}


Water::~Water()
{
}

string Water::fieldType(){
	return "Water";
}

bool Water::canEnter(){
	return false;
}

void Water::affect(){

}
