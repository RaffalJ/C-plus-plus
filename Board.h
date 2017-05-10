#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Field.h"

#include "Water.h"
#include "Tree.h"
#include "Road.h"
#include "Grass.h"
#include "Desert.h"
#include "Bound.h"

using namespace std;

class Board
{
private:
	vector<class Field *> fields;

	int width;
	int height;
public:
	Board();
	~Board();
	void loadBoard(SDL_Renderer* passed_renderer);
	void drawBoard(SDL_Renderer* passed_renderer);

	Field* getField(int x, int y);
};

