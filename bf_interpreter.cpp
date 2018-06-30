#include "bf_interpreter.h"

/*
 * Classic implementation of bf interpreter using pointers.
 */
void bf::interpret(const std::string filename) {
	std::string bf_text;
	try	{
		bf_text = read_input(filename);
	}
	catch (const std::exception& e) {
		throw e;
	}

	try	{
		char *ptr_data = new char[MAX_SIZE];
		int *ptr_loop = new int[MAX_SIZE];
		initialize(ptr_data, ptr_loop);

		for (int i = 0; i < bf_text.length(); i++) {
			switch (bf_text.at(i)) {
			case '>':
				++ptr_data;
				break;
			case '<':
				--ptr_data;
				break;
			case '+':
				++*ptr_data;
				break;
			case '-':
				--*ptr_data;
				break;
			case '.':
				putchar(*ptr_data);
				break;
			case ',':
				*ptr_data = getchar();
				break;
			case '[':
				++ptr_loop;
				*ptr_loop = i;
				break;
			case ']':
				if (*ptr_data != 0)
					i = *ptr_loop;
				else
					--ptr_loop;
				break;
			default:
				break;
			}
		}
	}
	catch (const std::exception& e)	{
		throw e;
	}	
}

/*
 * Simpler implementation using arrays and index variables.
 */
void bf::interpret_no_ptrs(const std::string filename) {
	std::string bf_text;
	try {
		bf_text = read_input(filename);
	}
	catch (const std::exception& e) {
		throw e;
	}

	try {
		char data[MAX_SIZE];
		int loop[MAX_SIZE];
		initialize(data, loop);

		int data_ind = 0;
		int loop_ind = 0;

		for (int i = 0; i < bf_text.length(); i++) {
			switch (bf_text.at(i)) {
			case '>':
				++data_ind;
				break;
			case '<':
				--data_ind;
				break;
			case '+':
				++data[data_ind];
				break;
			case '-':
				--data[data_ind];
				break;
			case '.':
				putchar(data[data_ind]);
				break;
			case ',':
				data[data_ind] = getchar();
				break;
			case '[':
				++loop_ind;
				loop[loop_ind] = i;
				break;
			case ']':
				if (data[data_ind] != 0)
					i = loop[loop_ind];
				else
					--loop_ind;
				break;
			default:
				break;
			}
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}

/*
 * Initialize the arrays to 0.
 */
void bf::initialize(char *data, int *loop) {
	for (int i = 0; i < MAX_SIZE; i++) {
		data[i] = 0;
		loop[i] = 0;
	}
}

/*
* Open the file and read in all of its input.
* Uses more memory, but doesn't have to keep the file open
* during interpretation. So... yeah.
*/
std::string bf::read_input(std::string filename) {

	std::stringstream data_reader;
	std::string line;
	try {
		std::ifstream file(filename);
		if (!file.is_open())
			throw std::exception("Error opening file.");

		while (file.is_open() && std::getline(file, line))
			data_reader << line;

		file.close();
	}
	catch (const std::exception& e) {
		throw std::exception("Error reading file: " + *e.what());
	}

	return data_reader.str();
}