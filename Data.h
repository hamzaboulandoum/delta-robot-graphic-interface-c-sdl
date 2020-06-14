#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;
class Data
{
public:
	Data(string file_location, int li);
	int data_return(string type);
private:
	string line = { 0 };
	string x_string_recap = "";
	string y_string_recap = "";
	string z_string_recap = "";
	char x_char_recap = 0;
	char y_char_recap = 0;
	char z_char_recap = 0;
	int x = 0, y = 0, z = 0;


};
