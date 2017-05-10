#include "stdafx.h"
#include "Road.h"


Road::Road(SDL_Renderer* passed_renderer, string FilePath, int width, int height, int x_pos, int y_pos)
:Place(passed_renderer, FilePath, width, height, x_pos, y_pos)
{
}

Road::~Road()
{
}

string Road::fieldType(){
	return "Road";
}

bool Road::canEnter(){
	return true;
}

void Road::affect(){

}