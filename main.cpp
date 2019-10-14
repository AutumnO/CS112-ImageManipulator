#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
#include <ctime>
using namespace std;

// *** NEED TO FIX REPEAT AND COMPOUNDING EFFECTS ***

int range_check(int value)
{
	if (value < 0)
	{
		value = 0;
	}
	else if (value > 255)
	{
		value = 255;
	}
	return value;
}

int main(int argc, char* argv[])
{
	cout << boolalpha;

	string input_file;
	string output_file;
	string img_effect_str;
	int img_effect;
	string format;
	string width_line;
	string height_line;
	int width; // change these three to ints
	int height;
	string max_pixel_line;
	int max_pixel;
	string next_line;

	cout << "Enter source file: ";
	cin >> input_file;

	cout << endl << "Enter destination file: ";
	cin >> output_file;
	

	ifstream fin;
	fin.open(input_file);

	if (fin.fail() == true)
	{
		cout << "Could not open " << input_file
			<< " for reading; Ending program" << endl;
		return EXIT_FAILURE;
	}

	ofstream fout;
	fout.open(output_file);

	if (fout.fail() == true)
	{
		cout << "Could not open " << output_file
			<< " for writing; Ending program" << endl;
		return EXIT_FAILURE;
	}

	getline(fin, format);			//print image format
	fout << format << endl;

	getline(fin, width_line, ' ');		// print width
	width = stoi(width_line);
	fout << width << " ";

	getline(fin, height_line);		// print height
	height = stoi(height_line);
	fout << height << endl;

	getline(fin, max_pixel_line);		//print max pixel value
	max_pixel = stoi(max_pixel_line);
	fout << max_pixel << endl;

	// int x = stoi(max_pixel); -- example of how to use stoi from AC

	//write rest of data

	vector<string> data_line{};
	vector<string> string_data{};
	vector<int> int_data{};
	string line;
	string current_line;
	string temp;
	int num_data;

	while (fin.good() == true) //not EOF, not error, etc.
	{
		getline(fin, line);
		data_line.push_back(line); // breaks data into individual lines
		// TODO: breaking data into lines may not be necessary
	}

	for (int i = 0; i < data_line.size(); i++) //breaks apart lines of data into vector of individual strings
	{
		current_line = data_line[i];

		//cout << "Current Line: " << current_line << endl;

		for (int s = 0; s <= current_line.length(); s++)
		{
			if (s == current_line.length())
			{
				if (temp.length() > 0)
				{
					string_data.push_back(temp);
					//cout << "Temp: " << temp << endl;
					temp = "";
				}
			}
			/*else if (s == current_line.length())
			{
				cout << "Temp: " << temp << endl;
			}*/
			else if (current_line.at(s) != ' ' && current_line.at(s) != '	')
			{
				temp.push_back(current_line.at(s));
			}
			else if ((current_line.at(s) == ' ' || current_line.at(s) == '	') && temp.length() > 0)
			{
				string_data.push_back(temp);
				// cout << "Temp (>0): " << temp << endl;
				temp = "";
			}
		}
	}

	for (int i = 0; i < (string_data.size() - 1); i++) //converts data vector of strings to data vector of ints
	{
		// TODO: check to make sure string_data[i] is an int
		num_data = stoi(string_data[i]);
		int_data.push_back(num_data);

		//cout << "S: " << string_data[i] << endl;
	}

	cout << endl << "*** Image Effects ***" << endl
		<< "1. Remove Red" << endl
		<< "2. Remove Green" << endl
		<< "3. Remove Blue" << endl
		<< "4. Negate Red" << endl
		<< "5. Negate Green" << endl
		<< "6. Negate Blue" << endl
		<< "7. Grayscale" << endl
		<< "8. Add Noise" << endl
		<< "9. High Contrast" << endl
		<< "Q. Quit" << endl;

	while ((img_effect_str != "Q") && (img_effect_str != "q"))
	{
		cout << endl << "Selection: ";
		cin >> img_effect_str;

		if ((img_effect_str != "Q") && (img_effect_str != "q"))
		{
			img_effect = stoi(img_effect_str);

			switch (img_effect)
			{
			case 1:
				img_effect_str = "Remove Red";
				break;
			case 2:
				img_effect_str = "Remove Green";
				break;
			case 3:
				img_effect_str = "Remove Blue";
				break;
			case 4:
				img_effect_str = "Negate Red";
				break;
			case 5:
				img_effect_str = "Negate Green";
				break;
			case 6:
				img_effect_str = "Negate Blue";
				break;
			case 7:
				img_effect_str = "Grayscale";
				break;
			case 8:
				img_effect_str = "Add Noise";
				break;
			case 9:
				img_effect_str = "High Contrast";
				break;
			default:
				cout << "Invalid Effect Selection" << endl;
				return EXIT_FAILURE;
			}
			cout << "Applying " << img_effect_str << " effect..." << endl;
		}
		else
		{
			cout << endl << "Program ending..." << endl;
		}

		// APPLY EFFECTS

		int value_1;
		int value_2;
		int value_3;
		int average;
		int noise_change;

		for (int i = 0; i < int_data.size(); i++)
		{
			switch (img_effect)
			{
			case 1:
				if (i % 3 == 0) //red values to zero
				{
					int_data[i] -= int_data[i];
				}
				break;

			case 2:
				if ((i + 2) % 3 == 0) //green values to zero
				{
					int_data[i] -= int_data[i];
				}
				break;

			case 3:
				if ((i + 1) % 3 == 0) //blue values to zero
				{
					int_data[i] -= int_data[i];
				}
				break;

			case 4:
				if (i % 3 == 0) //negate red
				{
					int_data[i] = 255 - int_data[i];
				}
				break;

			case 5:
				if ((i + 2) % 3 == 0) //negate green
				{
					int_data[i] = 255 - int_data[i];
				}
				break;

			case 6:
				if ((i + 1) % 3 == 0) //negate blue
				{
					int_data[i] = 255 - int_data[i];
				}
				break;

			case 7:
				if ((i % 3 == 0) && (i < int_data.size() - 2)) //grayscale
				{
					value_1 = int_data[i];
					value_2 = int_data[i + 1];
					value_3 = int_data[i + 2];
					average = ((value_1 + value_2 + value_3) / 3);
					int_data[i] = average;
					int_data[i + 1] = average;
					int_data[i + 2] = average; // 4 byte to 8 byte warning due to vs storing 1 as smaller value to save space
				}
				break;

			case 8:
				if ((i % 3 == 0) && (i < int_data.size() - 2)) //random noise
				{
					noise_change = (rand() % 20 - 10);

					if ((noise_change >= -10) && (noise_change <= 10))
					{
						value_1 = int_data[i] += noise_change;
						value_2 = int_data[i + 1] += noise_change;
						value_3 = int_data[i + 2] += noise_change;

						value_1 = range_check(value_1);
						value_2 = range_check(value_2);
						value_3 = range_check(value_3);

						int_data[i] = value_1;
						int_data[i + 1] = value_2;
						int_data[i + 2] = value_3;
					}
					else
					{
						cout << "Out of range Rand Value" << endl;
					}
				}
				break;

			case 9:
				if (int_data[i] > (255 / 2))
				{
					int_data[i] = 255;
				}
				else
				{
					int_data[i] = 0;
				}
				break;

			default:
				cout << "Invalid Effect Selection" << endl;
			}
		}
	}

	for (int i = 0; i < int_data.size(); i++) //prints the data
	{
		fout << " " << int_data[i];
		if ((i + 1) % 12 == 0)
		{
			fout << endl;
		}
	}

	fin.close();
	fout.close();

	return EXIT_SUCCESS;
}