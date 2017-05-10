

#include "stdafx.h"
#include <iostream>

#include "Game.h"

using namespace std;

int main(int argc, char* argv[]) {

	Game* game =  new Game();
	game->play();
	delete game;

	return 0;
}
	