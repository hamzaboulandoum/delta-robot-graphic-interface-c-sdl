#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<iostream>
#include"Text.h"
#include"Window.h"
using namespace std;

class Input
{
public:

	~Input();
	void pollEvents(SDL_Event& event, string& text);
	void display(int x,int y,int w,int h,string& text, SDL_Renderer* renderer);
	bool k = 0;
	bool enter_key = false;
	bool QUIT = false;


};
