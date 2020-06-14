#include "Data.h"

Data::Data(string file_location, int li) {
	line = { 0 };
	ifstream file;
	file.open(file_location);
	if (!file) {
		cerr << "file couldn't initialize " << endl;
	}

	int j = 0;
	do
	{
		getline(file, line);
		j++;
	} while ((j - 1) != li);

	cout << line << endl;


	x_string_recap = "";
	y_string_recap = "";
	z_string_recap = "";
	x_char_recap = 0;
	y_char_recap = 0;
	z_char_recap = 0;
	int i = 0;
	do
	{
		x_string_recap += x_char_recap;
		x_char_recap = line.at(i);
		i++;
	} while (x_char_recap != ',');
	x_string_recap.erase(0, 1);

	do
	{
		y_string_recap += y_char_recap;
		y_char_recap = line.at(i);
		i++;
	} while (y_char_recap != ',');
	y_string_recap.erase(0, 1);

	do
	{
		z_string_recap += z_char_recap;
		z_char_recap = line.at(i);
		i++;
	} while (z_char_recap != ',');
	z_string_recap.erase(0, 1);


	// now we will convert them into a string and then paste them into an array
	stringstream data_convertion_x(x_string_recap);
	data_convertion_x >> x;

	//
	stringstream data_convertion_y(y_string_recap);
	data_convertion_y >> y;

	//
	stringstream data_convertion_z(z_string_recap);
	data_convertion_z >> z;

	file.close();
}
int Data::data_return(string type) {
	if (type == "x") {

		return x;
	}
	if (type == "y") {

		return y;
	}
	if (type == "z") {

		return z;
	}




}
