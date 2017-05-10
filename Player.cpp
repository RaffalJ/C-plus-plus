#include "stdafx.h"
#include "Player.h"


Player::Player(SDL_Renderer* passed_renderer, string fimg_front, string fimg_back, string fimg_left, string fimg_right, int x, int y, int w, int h, string  name, double health, double attack){
	setName(name);
	setHealth(health);
	setAttack(attack);

	renderer = passed_renderer;

	image_front = NULL;
	image_front = IMG_LoadTexture(renderer, fimg_front.c_str());
	image_back = NULL;
	image_back = IMG_LoadTexture(renderer, fimg_back.c_str());
	image_right = NULL;
	image_right = IMG_LoadTexture(renderer, fimg_right.c_str());
	image_left = NULL;
	image_left = IMG_LoadTexture(renderer, fimg_left.c_str());
	
	if (image_front == NULL){
		cout << "Couldnt load : " << fimg_front.c_str() << endl;
	}
	if (image_back == NULL){
		cout << "Couldnt load : " << fimg_back.c_str() << endl;
	}
	if (image_left == NULL){
		cout << "Couldnt load : " << fimg_left.c_str() << endl;
	}
	if (image_right == NULL){
		cout << "Couldnt load : " << fimg_right.c_str() << endl;
	}

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	image_current = image_front;

	bool moveRight = false;
	bool moveLeft = false;
	bool moveUp = false;
	bool moveDown = false;
	speed = 2;
	timeCheck = SDL_GetTicks();
	timeCheck2 = SDL_GetTicks();
}


Player::~Player(){
	SDL_DestroyTexture(image_current);
}

void Player::Draw(){
	SDL_RenderCopy(renderer, image_current, NULL, &rect);
}

SDL_Texture* Player::getCurrentImage(){
	return image_current;
}
SDL_Texture* Player::getFrontImage(){
	return image_front;
}
SDL_Texture* Player::getBackImage(){
	return image_back;
}
SDL_Texture* Player::getLeftImage(){
	return image_left;
}
SDL_Texture* Player::getRightImage(){
	return image_right;
}

void Player::setCurrentImage(SDL_Texture* img){
	this->image_current = img;
}


void Player::setX(int x){
	rect.x = x;
}

void Player::setY(int y){
	rect.y = y;
}

void Player::setXY(int x, int y){
	rect.x = x;
	rect.y = y;
}

int Player::getX(){
	return rect.x;
}

int Player::getY(){
	return rect.y;
}

// ---------------------

void Player::setField(int field_x, int field_y){
	this->field_x = field_x;
	this->field_y = field_y;
}
double  Player::getFieldx(){
	return field_x;
}
double  Player::getFieldy(){
	return field_y;
}

// ---------------------

string Player::getName(){
	return name;
}

void Player::setName(string name){
	this->name = name;
}

double Player::getHealth(){
	return health;
}

void Player::setHealth(double health){
	this->health = health;
}

double Player::getAttack(){
	return attack;
}

void Player::setAttack(double attack){
	this->attack = attack;
}

double  Player::getMoveSpeed(){
	return moveSpeed;
}
void  Player::setMoveSpeed(double moveSpeed){
	this->moveSpeed = moveSpeed;
}