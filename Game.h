#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>

#include "Board.h"
#include "SDL_Setup.h"
#include "Sorcerer.h"

using namespace std;

class Game
{
private:
	Board* board;
	SDL_Setup* sdl_setup;
	bool quit;

	Sorcerer* player;

public:
	Game();
	~Game();
	void play();
};

