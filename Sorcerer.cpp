
#include "stdafx.h"
#include <iostream>
#include <string>
#include <string.h>

#include "Sorcerer.h"

using namespace std;

Sorcerer::Sorcerer(SDL_Renderer* passed_renderer, string fimg_front, string fimg_back, string fimg_left, string fimg_right, int x, int y, int w, int h, string  name, double health, double attack)
:Player(passed_renderer,fimg_front,fimg_back, fimg_left,fimg_right, x, y, w, h, name, health, attack)
{
	setMoveSpeed(1);

	MoveFRight = true;
	MoveFLeft = true;
	MoveFUp = true;
	MoveFDown = true;
	fr2 = true;
	fl2 = true;
	fd2 = true;
	fu2 = true;
}


Sorcerer::~Sorcerer(){

}

string Sorcerer::type(){
	return "Sorcerer";
}

void Sorcerer::move(SDL_Event* sdl_event, SDL_Renderer* renderer,Sorcerer* sorcerer){
	speed = getMoveSpeed();
	switch (sdl_event->type)
	{
	case SDL_KEYDOWN:
		switch (sdl_event->key.keysym.sym)
		{
		case SDLK_a:
			MoveLeft = true;
			break;
		case SDLK_s:
			MoveDown = true;
			break;
		case SDLK_w:
			MoveUp = true;
			break;
		case SDLK_d:
			MoveRight = true;
			break;
		default:
			break;
		}
		break;
	case SDL_KEYUP:
		switch (sdl_event->key.keysym.sym)
		{
		case SDLK_a:
			MoveLeft = false;
			break;
		case SDLK_s:
			MoveDown = false;
			break;
		case SDLK_w:
			MoveUp = false;
			break;
		case SDLK_d:
			MoveRight = false;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	if ((timeCheck + 20) < SDL_GetTicks())
	{
		if ((timeCheck2 + 3000 * 20) < SDL_GetTicks()){
			SDL_RenderClear(renderer);
			timeCheck2 = SDL_GetTicks();
		}

		if (MoveRight)
		{
			sorcerer->setCurrentImage(sorcerer->getRightImage());
			if ((sorcerer->getX() + 76) > (20 * 50) || fr2==false){
				fu2 = false;
				fd2 = false;
				sorcerer->setX(sorcerer->getX());
			}
			else {
				sorcerer->setX(sorcerer->getX() + speed);
			}
		}
		if (MoveLeft)
		{
			sorcerer->setCurrentImage(sorcerer->getLeftImage());
			if ((sorcerer->getX()) < 50  || fl2==false){
				fu2 = false;
				fd2 = false;
				sorcerer->setX(sorcerer->getX());
			}
			else {
				sorcerer->setX(sorcerer->getX() - speed);
			}
		}
		if (MoveDown)
		{
			sorcerer->setCurrentImage(sorcerer->getFrontImage());
			if ((sorcerer->getY()) > (12 * 50) || fd2 == false){
				sorcerer->setY(sorcerer->getY());
			}
			else {
				sorcerer->setY(sorcerer->getY() + speed);
			}
		}
		if (MoveUp)
		{
			sorcerer->setCurrentImage(sorcerer->getBackImage());
			if ((sorcerer->getY()) < 200 || fu2 == false){
				sorcerer->setY(sorcerer->getY());
			}
			else {
				sorcerer->setY(sorcerer->getY() - speed);
			}
		}
		timeCheck = SDL_GetTicks();
	}
}

void Sorcerer::field_collision(Sorcerer* sorcerer,Board* board){
	// -----------------------------------------------------------------------------------------------------------------------------------
	bool change = false;

	double xr1 = sorcerer->getX()+24;
	double xr2 = board->getField(sorcerer->getFieldx() + 1, sorcerer->getFieldy())->getXpos();
	double xr3 = sorcerer->getX();
	double xr4 = board->getField(sorcerer->getFieldx() + 1, sorcerer->getFieldy())->getXpos()+50;

	double yr1 = sorcerer->getY() + 45;
	double yr2 = board->getField(sorcerer->getFieldx() + 1, sorcerer->getFieldy())->getYpos();
	double yr3 = sorcerer->getY();
	double yr4 = board->getField(sorcerer->getFieldx() + 1, sorcerer->getFieldy())->getYpos() + 50;

	fr1 = board->getField(sorcerer->getFieldx() + 1, sorcerer->getFieldy())->canEnter();
	fr2 = true;

	if (xr1 >= xr2 && xr3 <=xr4 && yr1 >= yr2 && yr3 <= yr4) {
		if (fr1){
			sorcerer->setField(sorcerer->getFieldx() + 1, sorcerer->getFieldy());
		}
		else if ((xr1+36) >= xr2  && (xr3<xr4) && (yr1+45)>=yr2 && (yr3<yr4)){
			fr2 = false;
		}
	}

	double xl1 = sorcerer->getX() + 24;
	double xl2 = board->getField(sorcerer->getFieldx() - 1, sorcerer->getFieldy())->getXpos();
	double xl3 = sorcerer->getX();
	double xl4 = board->getField(sorcerer->getFieldx() - 1, sorcerer->getFieldy())->getXpos() + 50;

	double yl1 = sorcerer->getY() + 45;
	double yl2 = board->getField(sorcerer->getFieldx() - 1, sorcerer->getFieldy())->getYpos();
	double yl3 = sorcerer->getY();
	double yl4 = board->getField(sorcerer->getFieldx() - 1, sorcerer->getFieldy())->getYpos() + 50;


	fl1 = board->getField(sorcerer->getFieldx() - 1, sorcerer->getFieldy())->canEnter();
	fl2 = true;

	if (xl1 >= xl2 && xl3 <= xl4 && yl1 >= yl2 && yl3 <= yl4) {
		if (fl1){
			sorcerer->setField(sorcerer->getFieldx() - 1, sorcerer->getFieldy());
		}
		else if ((xl1 + 36) >= xl2 && (xl3<xl4) && (yl1 + 45) >= yl2 && (yl3<yl4)){
			fl2 = false;
		}
	}

	double xd1 = sorcerer->getX() + 24;
	double xd2 = board->getField(sorcerer->getFieldx(), sorcerer->getFieldy() + 1)->getXpos();
	double xd3 = sorcerer->getX();
	double xd4 = board->getField(sorcerer->getFieldx(), sorcerer->getFieldy() + 1)->getXpos() + 50;

	double yd1 = sorcerer->getY() + 45;
	double yd2 = board->getField(sorcerer->getFieldx(), sorcerer->getFieldy() + 1)->getYpos();
	double yd3 = sorcerer->getY();
	double yd4 = board->getField(sorcerer->getFieldx(), sorcerer->getFieldy() + 1)->getYpos() + 50;


	fd1 = board->getField(sorcerer->getFieldx(), sorcerer->getFieldy() + 1)->canEnter();
	fd2 = true;
	if (xd1 >= xd2 && xd3 <= xd4 && yd1 >= yd2 && yd3 <= yd4) {
		if (fd1){
			sorcerer->setField(sorcerer->getFieldx(), sorcerer->getFieldy() + 1);
		}
		else if ((xd1 + 36) >= xd2 && (xd3<xd4) && (yd1 + 45) >= yd2 && (yd3<yd4)){
			fd2 = false;
		}
	}

	double xu1 = sorcerer->getX() + 24;
	double xu2 = board->getField(sorcerer->getFieldx(), sorcerer->getFieldy() - 1)->getXpos();
	double xu3 = sorcerer->getX();
	double xu4 = board->getField(sorcerer->getFieldx(), sorcerer->getFieldy() - 1)->getXpos() + 50;

	double yu1 = sorcerer->getY() + 45;
	double yu2 = board->getField(sorcerer->getFieldx(), sorcerer->getFieldy() - 1)->getYpos();
	double yu3 = sorcerer->getY();
	double yu4 = board->getField(sorcerer->getFieldx(), sorcerer->getFieldy() - 1)->getYpos() + 50;


	fu1 = board->getField(sorcerer->getFieldx(), sorcerer->getFieldy() - 1)->canEnter();
	fu2 = true;
	if (xu1 >= xu2 && xu3 <= xu4 && yu1 >= yu2 && yu3 <= yu4) {
		if (fu1){
			sorcerer->setField(sorcerer->getFieldx(), sorcerer->getFieldy() - 1);
		}
		else if ((xu1 + 36) >= xu2 && (xu3<xu4) && (yu1 + 45) >= yu2 && (yu3<yu4)){
			fu2 = false;
		}
	}

}