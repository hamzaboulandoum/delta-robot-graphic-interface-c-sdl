#include"Window.h"
#include "Rect.h"
#include "Text.h"
#include<stdlib.h>
#include<time.h>
#include<string>
#include<sstream>
#include<stdio.h>
#include"Input.h"
#include"Data.h"
using namespace std;

//function for events polling and controlling
void pollEvents(Window& window, Rect& initialization_delta, Rect& manuel, Rect& file, Rect& draw_path) {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		window.pollEvents(event);
		initialization_delta.pollEvents(window, event);
		manuel.pollEvents(window, event);
		file.pollEvents(window, event);
		draw_path.pollEvents(window, event);
	}
}


int main(int argc, char* argv[]) {
	Window window("hamza_ window", 800, 600);
	Rect initialization_delta(100, 200, 400, 450, "res/init.png");
	Rect manuel(100, 200, 150, 300, "res/manuel.png");
	Rect file(100, 200, 400, 300, "res/file.png");
	Rect draw_path(100, 200, 650, 300, "res/draw.png");
	Rect background(600,800, 400, 300, "res/background.png");
	Text chose_mode(Window::renderer, "res/font.ttf", 300, "Chose Mode:", { 255,0,0,255 });

	while (window._closed == false) {
		background.draw();
		pollEvents(window, initialization_delta, manuel, file, draw_path);
		initialization_delta.draw();
		manuel.draw();
		file.draw();
		draw_path.draw();
		chose_mode.display(150, 100, 500, 50, Window::renderer);

		if (manuel.launch == true) {// apres avoir cliqué sur manuel entry
			Text manuel_mode(Window::renderer, "res/font.ttf", 200, "Manuel Mode", { 255,0,0,255 });
			Text enter_coordinates(Window::renderer, "res/font.ttf", 200, "Enter coordinates:", { 255,255,0,255 });
			Text job_done(Window::renderer, "res/font.ttf", 205, "--positions aquired successfully--:", { 0,0,255,255 });
			Text X_text(Window::renderer, "res/font.ttf", 200, "X:", { 255,255,0,255 });
			Text Y_text(Window::renderer, "res/font.ttf", 200, "Y:", { 255,255,0,255 });
			Text Z_text(Window::renderer, "res/font.ttf", 200, "Z:", { 255,255,0,255 });

			SDL_Event event;

			string x_string = "";
			Input x_input;
			while (true) {
				x_input.pollEvents(event, x_string);
				background.draw();
				manuel_mode.display(150, 110, 500, 50, Window::renderer);
				enter_coordinates.display(250, 210, 300, 30, Window::renderer);
				X_text.display(150, 300, 50, 50, Window::renderer);

				if (x_input.enter_key == false && x_string.length() > 0) {
					x_input.display(205, 300, 100, 50, x_string, Window::renderer);
				}
				if (x_input.enter_key == true) {
					break;
				}
				window.clear();
			}
			x_input.enter_key = false;
			cout << x_string << endl;
			string y_string;
			Input y_input;
			while (true) {
				background.draw();
				X_text.display(150, 300, 50, 50, Window::renderer);
				x_input.display(205, 300, 100, 50, x_string, Window::renderer);
				y_input.pollEvents(event, y_string);
				Y_text.display(350, 300, 50, 50, Window::renderer);
				manuel_mode.display(150, 110, 500, 50, Window::renderer);
				enter_coordinates.display(250, 210, 300, 30, Window::renderer);

				if (y_input.enter_key == false && y_string.length() > 0) {
					y_input.display(405, 300, 50, 50, y_string, Window::renderer);
				}
				if (y_input.enter_key == true) {
					break;
				}
				window.clear();
			}
			y_input.enter_key = false;
			cout << y_string << endl;

			string z_string;
			Input z_input;
			while (true) {
				background.draw();
				z_input.pollEvents(event, z_string);
				X_text.display(150, 300, 50, 50, Window::renderer);
				Y_text.display(350, 300, 50, 50, Window::renderer);
				x_input.display(205, 300, 100, 50, x_string, Window::renderer);
				y_input.display(405, 300, 100, 50, y_string, Window::renderer);

				manuel_mode.display(150, 110, 500, 50, Window::renderer);
				enter_coordinates.display(250, 210, 300, 30, Window::renderer);

				Z_text.display(550, 300, 50, 50, Window::renderer);

				if (z_input.enter_key == false && z_string.length() > 0) {
					z_input.display(605, 300, 100, 50, z_string, Window::renderer);
				}
				if (z_input.enter_key == true) {
					break;
				}
				window.clear();
			}
			z_input.enter_key = false;
			cout << z_string << endl;

			// converting string into integers
			int x = 0, y = 0, z = 0;
			stringstream convert_x(x_string);
			convert_x >> x;
			cout << "the value of x is:" << x << endl;

			stringstream convert_y(y_string);
			convert_y >> y;
			cout << "the value of y is:" << y << endl;

			stringstream convert_z(z_string);
			convert_z >> z;
			cout << "the value of z is:" << z << endl;
			// i will add a part to validate these results using our convertion equations 
			z_input.display(605, 300, 100, 50, z_string, Window::renderer);
			job_done.display(150, 450, 500, 50, Window::renderer);
			window.clear();
			SDL_Delay(2000);
			cout << "well done" << endl;

		}
		manuel.launch = false;


		if (file.launch == true) {
			// first i must set up how the screen looks like
			SDL_Event event;
			Text file_mode(Window::renderer, "res/font.ttf", 100, "file read Mode", { 255,0,0,255 });
			Text file_location(Window::renderer, "res/font.ttf", 75, "enter your file location--:", { 0,255,0,255 });
			Text job_done(Window::renderer, "res/font.ttf", 205, "--positions aquired successfully--:", { 0,0,255,255 });
			// loop until we get our file value
			string file_location_string = "";
			Input input_location;
			while (true) {
				background.draw();
				input_location.pollEvents(event, file_location_string);
				file_mode.display(150, 110, 500, 50, Window::renderer);
				file_location.display(50,300, 300, 50, Window::renderer);
				if (input_location.enter_key == false && file_location_string.length() > 0) {
					input_location.display(360, 300, 250, 50, file_location_string, Window::renderer);
				}
				if (input_location.enter_key == true) {
					break;
				}
				window.clear();
			}
			cout << file_location_string << endl;
			int j = 0;
			int const lines = 10;
			int const columns = 3;
			int x = 0, y = 0, z = 0;
			// c'est a l'interieur de cette boucle qu'on va envoyer tous ce dont on a besoin a l'arduino
			for (int li = 0; li < lines; li++) {
				Data data(file_location_string, li);

				x = data.data_return("x");
				y = data.data_return("y");
				z = data.data_return("z");

				cout << "the value of x is:" << x << endl;
				cout << "the value of y is:" << y << endl;
				cout << "the value of z is:" << z << endl;
				cout << "**************" << endl;
			}
			background.draw();
			file_mode.display(150, 110, 500, 50, Window::renderer);
			file_location.display(50, 300, 300, 50, Window::renderer);
			job_done.display(150, 400, 500, 50, Window::renderer);
			window.clear();
			SDL_Delay(3000);
			cout << "well done" << endl;
		}

		file.launch = false;




		if (draw_path.launch == true) {
			cout << "draaaw" << endl;
			draw_path.launch = false;
		}
		if (initialization_delta.launch == true) {
			cout << "init" << endl;
			initialization_delta.launch = false;
		}
		window.clear();
	}
	return 0;
}