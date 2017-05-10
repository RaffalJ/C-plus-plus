#include "stdafx.h"
#include "Board.h"


Board::Board(){

}


Board::~Board(){
	for (vector<Field*>::iterator it = fields.begin(); it != fields.end(); ++it)
	{
		delete *it;
	}
	fields.clear();
}

void Board::loadBoard(SDL_Renderer* passed_renderer){
	int startx = 0;
	int starty = 150;
	string x, y;
	int escape = 0;
	string tab[20][20];
	string filename = "map3.txt";
	ifstream file;
	file.open(filename.c_str());
	while (!file.eof()) {
		getline(file, x);
		getline(file, y);
		width = atoi(x.c_str());
		height = atoi(y.c_str());
		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < height+3; ++j) {
				file >> tab[i][j];
				if (tab[i][j] == "G") {
					fields.push_back(new Grass(passed_renderer, "images/field/Grass.bmp", 50, 50, startx, starty));
				}
				else if (tab[i][j] == "T") {
					fields.push_back(new Tree(passed_renderer, "images/field/Tree.bmp", 50, 50, startx, starty));
				}
				else if (tab[i][j] == "W") {
					fields.push_back(new Water(passed_renderer, "images/field/Water.bmp", 50, 50, startx, starty));
				}
				else if (tab[i][j] == "R") {
					fields.push_back(new Road(passed_renderer, "images/field/Road.bmp", 50, 50, startx, starty));
				}
				else if (tab[i][j] == "B") {
					fields.push_back(new Bound(passed_renderer, "images/field/Rock.bmp", 50, 50, startx, starty));
				}
				else if (tab[i][j] == "P") {
					fields.push_back(new Desert(passed_renderer, "images/field/Desert.bmp", 50, 50, startx, starty));
				}
				escape++;
				if (escape % 20 == 0){
					starty += 50;
					startx = -50;
				}
				startx += 50;
			}

		}

		break;
	}
}

void Board::drawBoard(SDL_Renderer* passed_renderer){
	vector<class Field *>::iterator it;
	for (it = fields.begin(); it != fields.end(); ++it) {
		(*it)->Draw();
	}
}

Field *Board::getField(int x, int y){
	return (&fields)->at(((y - 1) * width) + (x - 1));
}
