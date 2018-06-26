#include "bf_interpreter.h"

void bf::initialize(char* data, char * loop)	{
	for (int i = 0; i < MAX_SIZE; i++) {
		data[i] = 0;
		loop[i] = 0;
	}
}

std::string bf::read_input(std::string filename) {
	std::ifstream file(filename);
	std::stringstream data_reader;
	std::string line;
	
	if (!file.is_open())
		throw std::exception("Error opening file.");
	
	while (file.is_open() && std::getline(file, line))
		data_reader << line;

	file.close();

	return data_reader.str();
}

void bf::interpret(const std::string filename) {
	try	{
		std::string bf_text = read_input(filename);

		char data[MAX_SIZE];
		char loop[MAX_SIZE];
		initialize(data, loop);

		char *ptr_data = data;
		char *ptr_loop = loop;

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

void bf::interpret_no_ptrs(const std::string filename) {
	try
	{
		std::string bf_text = read_input(filename);

		char data[MAX_SIZE];
		char loop[MAX_SIZE];
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
