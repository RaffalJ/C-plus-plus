#include "stdafx.h"
#include "Desert.h"


Desert::Desert(SDL_Renderer* passed_renderer, string FilePath, int width, int height, int x_pos, int y_pos)
:Place(passed_renderer, FilePath, width, height, x_pos, y_pos){

}


Desert::~Desert()
{
}

string Desert::fieldType(){
	return "Desert";
}

bool Desert::canEnter(){
	return true;
}

void Desert::affect(){

}