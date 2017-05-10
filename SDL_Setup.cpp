#include "stdafx.h"
#include "SDL_Setup.h"


SDL_Setup::SDL_Setup(bool* quit, int passed_ScreenWidth, int passed_ScreenHeight){
	window = NULL;
	window = SDL_CreateWindow("MMO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, passed_ScreenWidth, passed_ScreenHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (window == NULL){
		*quit = true;
	}

	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	mainEvent = new SDL_Event();
}


SDL_Setup::~SDL_Setup(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}

SDL_Renderer* SDL_Setup::getRenderer(){
	return renderer;
}

SDL_Event* SDL_Setup::getMainEvent(){
	return mainEvent;
}

void  SDL_Setup::begin(){
	SDL_PollEvent(mainEvent);
	//SDL_RenderClear(renderer);
}

void  SDL_Setup::end(){
	SDL_RenderPresent(renderer);
}

