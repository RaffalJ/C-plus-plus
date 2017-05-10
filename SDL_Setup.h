#pragma once
class SDL_Setup{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;

public:
	SDL_Setup(bool* quit, int passed_ScreenWidth, int passed_ScreenHeight);
	~SDL_Setup();

	SDL_Renderer* getRenderer();
	SDL_Event* getMainEvent();

	void begin();
	void end();
};
