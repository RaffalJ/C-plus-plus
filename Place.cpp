#include "stdafx.h"
#include "Place.h"


Place::Place(SDL_Renderer* passed_renderer, string FilePath, int width, int height, int x_pos, int y_pos)
:Field(passed_renderer, FilePath, width, height, x_pos, y_pos)
{

}



Place::~Place()
{

}
