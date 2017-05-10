#include "stdafx.h"
#include "Grass.h"


Grass::Grass(SDL_Renderer* passed_renderer, string FilePath, int width, int height, int x_pos, int y_pos)
:Place(passed_renderer, FilePath, width, height, x_pos, y_pos){

}


Grass::~Grass()
{
}

string Grass::fieldType(){
	return "Grass";
}

bool Grass::canEnter(){
	return true;
}

void Grass::affect(){

}