#pragma once
#include "Window.h"
#include<SDL_image.h>
#include "Input.h"
class Rect
{
public:
	//	Rect(int h, int w, int x, int y, int red, int green, int blue, int alpha);
	Rect(int h, int w, int x, int y, const string& image_path);
	~Rect();

	void draw();
	void pollEvents(Window& window, SDL_Event& event);
	bool end = 0;
	bool launch = 0;
	bool check = 0;
	bool QUIT = false;
private:
	int _positionClick_X = 0;
	int _positionClick_Y = 0;
	int _w = 0, _h = 0;
	int _x = 0, _y = 0;
	int _red = 0, _green = 0, _blue = 0, _alpha = 0;
	SDL_Texture* _texture = nullptr;
	bool click_condition = 0;
};


