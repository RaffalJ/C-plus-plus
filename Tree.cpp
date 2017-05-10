#include "stdafx.h"
#include "Tree.h"


Tree::Tree(SDL_Renderer* passed_renderer, string FilePath, int width, int height, int x_pos, int y_pos)
:Field(passed_renderer, FilePath, width, height, x_pos, y_pos)
{
}


Tree::~Tree()
{
}

string Tree::fieldType(){
	return "Tree";
}

bool Tree::canEnter(){
	return false;
}

void Tree::affect(){

}
