#include "Input.h"

Input::~Input() {
}


void Input::pollEvents(SDL_Event& event, string& text) {
	//Special key input
	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			exit(0);
			SDL_StopTextInput();
			TTF_Quit();
			IMG_Quit();
			SDL_Quit();
		}
		if (event.type == SDL_KEYDOWN)
		{
			//Handle backspace
			if (event.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0)
			{
				//lop off character
				text.pop_back();
				k = 1;
			}
			//Handle copy
			else if (event.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
			{
				SDL_SetClipboardText(text.c_str());
			}
			//Handle paste
			else if (event.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
			{
				text = SDL_GetClipboardText();
				//k = 1;
			}
			else if (event.key.keysym.scancode == SDL_SCANCODE_RETURN)
			{
				//k = 0;
				enter_key = true;
			}
		}
		//Special text input event
		else if (event.type == SDL_TEXTINPUT)
		{
			//Not copy or pasting
			if (!(SDL_GetModState() & KMOD_CTRL && (event.text.text[0] == 'c' || event.text.text[0] == 'C' || event.text.text[0] == 'v' || event.text.text[0] == 'V')))
			{
				//Append character
				text += event.text.text;
				//k = 1;// k=0 means you clicked enter button 
			}
		}
	}
}

void Input::display(int x, int y, int w, int h, string& text, SDL_Renderer * renderer) {
	Text text3(Window::renderer, "res/font.ttf", 50,text, {255,0,0,255 });
	text3.display2(x,y,renderer);
}