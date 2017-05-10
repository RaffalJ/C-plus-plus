
#include "stdafx.h"

#include "Game.h"


Game::Game(){
	this->board = new Board;
	quit = false;
	sdl_setup = new SDL_Setup(&quit, 20 * 50, 14 * 50);

	string file1 = "images/wizard/wizard_front.png";
	string file2 = "images/wizard/wizard_back.png";
	string file3 = "images/wizard/wizard_left.png";
	string file4 = "images/wizard/wizard_right.png";
	int startx=101;
	int starty=200;
	int pl_width=24;
	int pl_height=45;
	string pl_name = "Geralt";
	int pl_health=100;
	int pl_attack=10;

	player = new Sorcerer(sdl_setup->getRenderer(), file1, file2, file3, file4, startx, starty, pl_width, pl_height, pl_name, pl_health, pl_attack);
	player->setMoveSpeed(3);
}



Game::~Game(){
	delete board;
	delete sdl_setup;
}

void Game::play(){
	board->loadBoard(sdl_setup->getRenderer());
	board->getField(3, 2)->setEmpty(false);
	player->setField(3, 2);

	while (!quit && sdl_setup->getMainEvent()->type != SDL_QUIT){
		sdl_setup->begin();
		//SDL_RenderClear(sdl_setup->getRenderer());

		board->drawBoard(sdl_setup->getRenderer());
		player->Draw();
		player->move(sdl_setup->getMainEvent(), sdl_setup->getRenderer(), player);
		player->field_collision(player, board);

		sdl_setup->end();
	}

}