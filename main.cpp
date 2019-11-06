#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
#include <ctime>
using namespace std;

// May want to create classes later
// ****** My blur effect although running 10 times, seems less blurred than example pic

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

vector<vector<int>> flip_horizontal(vector<vector<int>> data, int num_rows, int num_cols) // not currently used!!
{
	vector<vector<int>> temp = data;
	int row_counter = (num_rows - 1);
	int col_counter = (num_cols - 1);

	return data;
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

	/*
	//write rest of data

	vector<string> data_line{};
	vector<string> string_data{};
	vector<int> temp_data_row{};
	vector<int> int_all_data{};
	vector<vector<int>> int_data{};
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

		for (int s = 0; s <= current_line.length(); s++)
		{
			if (s == current_line.length())
			{
				if (temp.length() > 0)
				{
					string_data.push_back(temp);
					temp = "";
				}
			}
			else if (current_line.at(s) != ' ' && current_line.at(s) != '	')
			{
				temp.push_back(current_line.at(s));
			}
			else if ((current_line.at(s) == ' ' || current_line.at(s) == '	') && temp.length() > 0)
			{
				string_data.push_back(temp);
				temp = "";
			}
		}
	}

	for (int i = 0; i < string_data.size(); i++) //converts data vector of strings to data vector of ints
	{
		// TODO: check to make sure string_data[i] is an int
		num_data = stoi(string_data[i]);
		int_all_data.push_back(num_data);
	}

	for (int i = 0; i < int_all_data.size(); i++) //split int vector into row vectors
	{
		temp_data_row.push_back(int_all_data[i]);
		cout << "M" << i << ": " << int_all_data[i] << endl;
		if (i == width)
		{
			for (int k = 0; k < temp_data_row.size(); k++)
			{
				cout << k << ": " << temp_data_row[k] << endl;
			}
			
			int_data.push_back(temp_data_row);
			temp_data_row = {};
		}
	}
	*/

	// *******************************

	vector<vector<int>> data{};
	int num_rows = height;
	int num_cols = (width * 3);

	data.resize(num_rows);

	for (int i = 0; i < num_rows; i++)
	{
		data[i].resize(num_cols);
	}

	if (fin.good() == true)
	{
		int next_num = 0;
		for (int r = 0; r < num_rows; r++)
		{
			for (int c = 0; c < num_cols; c++)
			{
				fin >> next_num;
				data[r][c] = next_num;
				// cout << c << ": " << next_num << endl;
			}
		}
	}

	// *******************************

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
		<< "10. Flip Horizontally" << endl
		<< "11. Flip Vertically" << endl
		<< "12. Blur" << endl
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
			case 10:
				img_effect_str = "Flip Horizontally";
				break;
			case 11:
				img_effect_str = "Flip Vertically";
				break;
			case 12:
				img_effect_str = "Blur";
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
			break;
		}

		// APPLY EFFECTS

		vector<vector<int>> temp = data; // *************
		int row_counter = (num_rows - 1);
		int col_counter = (num_cols - 1);

		int value_1 = 0;
		int value_2 = 0;
		int value_3 = 0;
		int average = 0;
		int noise_change;
		int blur_extent = 10;

		if (img_effect < 10)
		{
			for (int i = 0; i < data.size(); i++)
			{
				for (int j = 0; j < data[i].size(); j++)
				{
					switch (img_effect)
					{
					case 1:
						if (j % 3 == 0) //red values to zero
						{
							data[i][j] -= data[i][j];
						}
						break;

					case 2:
						if ((j + 2) % 3 == 0) //green values to zero
						{
							data[i][j] -= data[i][j];
						}
						break;

					case 3:
						if ((j + 1) % 3 == 0) //blue values to zero
						{
							data[i][j] -= data[i][j];
						}
						break;

					case 4:
						if (j % 3 == 0) //negate red
						{
							data[i][j] = 255 - data[i][j];
						}
						break;

					case 5:
						if ((j + 2) % 3 == 0) //negate green
						{
							data[i][j] = 255 - data[i][j];
						}
						break;

					case 6:
						if ((j + 1) % 3 == 0) //negate blue
						{
							data[i][j] = 255 - data[i][j];
						}
						break;

					case 7:
						if ((j % 3 == 0) && (j < data[i].size() - 2)) //grayscale
						{
							value_1 = data[i][j];
							value_2 = data[i][j + 1];
							value_3 = data[i][j + 2];
							average = ((value_1 + value_2 + value_3) / 3);
							data[i][j] = average;
							data[i][j + 1] = average;
							data[i][j + 2] = average; // 4 byte to 8 byte warning due to vs storing 1 as smaller value to save space
						}
						break;

					case 8:
						if ((j % 3 == 0) && (j < data[i].size() - 2)) //random noise
						{
							noise_change = (rand() % 20 - 10);

							if ((noise_change >= -10) && (noise_change <= 10))
							{
								value_1 = data[i][j] += noise_change;
								value_2 = data[i][j + 1] += noise_change;
								value_3 = data[i][j + 2] += noise_change;

								value_1 = range_check(value_1);
								value_2 = range_check(value_2);
								value_3 = range_check(value_3);

								data[i][j] = value_1;
								data[i][j + 1] = value_2;
								data[i][j + 2] = value_3;
							}
							else
							{
								cout << "Out of range Rand Value" << endl;
							}
						}
						break;

					case 9:
						if (data[i][j] > (255 / 2))
						{
							data[i][j] = 255;
						}
						else
						{
							data[i][j] = 0;
						}
						break;

					default:
						cout << "Invalid Effect Selection" << endl;
					}
				}
			}
		}
		else if (img_effect >= 10)
		{
			switch (img_effect)
			{
			case 10:									// flip horizontally
				if (row_counter >= 0)
				{
					for (int i = 0; i < temp.size(); i++)
					{
						col_counter = (num_cols - 1);
						for (int j = 0; j < temp[i].size(); j += 3)
						{
							data[i][col_counter - 2] = temp[i][j];
							data[i][col_counter - 1] = temp[i][j + 1];
							data[i][col_counter] = temp[i][j + 2];
							col_counter -= 3;
						}
						row_counter -= 1;
					}
				}
				break;

			case 11:									// flip vertically
				if (row_counter >= 0)
				{
					for (int i = 0; i < temp.size(); i++)
					{
						data[row_counter] = temp[i];
						row_counter -= 1;
					}
				}
				break;

			case 12:
				if (row_counter >= 0)
				{
					for (int c = 0; c < blur_extent; c++)
					{
						temp = data;
						for (int i = 0; i < data.size(); i++) // change for each row
						{
							for (int j = 0; j < data[i].size(); j++)
							{
								if ((j == 0) || (j == 1) || (j == 2))
								{
									value_1 = temp[i][j];
									value_2 = temp[i][j + 3];
									average = ((value_1 + value_2) / 2);
									data[i][j] = average;
								}
								else if ((j == col_counter) || (j == (col_counter - 1)) || (j == (col_counter - 2)))
								{
									value_1 = temp[i][j - 3];
									value_2 = temp[i][j];
									average = ((value_1 + value_2) / 2);
									data[i][j] = average;
								}
								else
								{
									value_1 = temp[i][j - 3];
									value_2 = temp[i][j];
									value_3 = temp[i][j + 3];
									average = ((value_1 + value_2 + value_3) / 3);
									data[i][j] = average;
								}
							}
						}

						temp = data;
						for (int j = 0; j < num_cols; j++) // change for each column
						{
							for (int i = 0; i < num_rows; i++)
							{
								if (i == 0)
								{
									value_1 = temp[i][j];
									value_2 = temp[i + 1][j];
									average = ((value_1 + value_2) / 2);
									data[i][j] = average;
								}
								else if (i == (num_rows - 1))
								{
									value_1 = temp[i - 1][j];
									value_2 = temp[i][j];
									average = ((value_1 + value_2) / 2);
									data[i][j] = average;
								}
								else
								{
									value_1 = temp[i - 1][j];
									value_2 = temp[i][j];
									value_3 = temp[i + 1][j];
									average = ((value_1 + value_2 + value_3) / 3);
									data[i][j] = average;
								}
							}
						}
					}
				}
				break;

			default:
				cout << "Invalid Effect Selection" << endl;
			}
		}
	}

	for (int i = 0; i < data.size(); i++) //prints the data
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			fout << " " << data[i][j];
			if ((j + 1) % 12 == 0)
			{
				fout << endl;
			}
		}
	}

	fin.close();
	fout.close();

	return EXIT_SUCCESS;
}