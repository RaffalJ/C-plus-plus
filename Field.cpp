#include "stdafx.h"
#include "Field.h"


Field::Field(SDL_Renderer* passed_renderer, string FilePath, int width, int height, int x_pos, int y_pos){
	renderer = passed_renderer;
	image = NULL;
	image = IMG_LoadTexture(renderer, FilePath.c_str());
	if (image == NULL){
		cout << "Couldnt load : " << FilePath.c_str() << endl;
	}
	this->x_pos = x_pos;
	this->y_pos = y_pos;
	rect.x = x_pos;
	rect.y = y_pos;
	rect.w = width;
	rect.h = height;
	empty = true;
}


Field::~Field(){
	SDL_DestroyTexture(image);
}

void Field::setEmpty(bool empty){
	this->empty = empty;
}

bool Field::getEmpty(){
	return empty;
}

void Field::Draw(){
	SDL_RenderCopy(renderer, image, NULL, &rect);
}

double Field::getXpos(){
	return x_pos;
}

double Field::getYpos(){
	return y_pos;
}