#include "main.h"

int main(int argc, char **argv) {
	try	{
		check_arg_size(argc);

		std::string filename = argv[1];
		parse_filename(filename);

		int mode = get_mode(argc, argv);

		switch (mode) {
		case 1:
			bf::interpret(filename);
			break;
		case 2:
			bf::interpret_no_ptrs(filename);
			break;
		}
	}
	catch (const std::exception& e)	{
		std::cerr << e.what();
	}
	
	return 0;
}

/*
 * Essentially, this method just asserts that the file name is of the correct type.
 * Getting reeeeal fancy with this one.
 */
void parse_filename(std::string filename) {
	std::size_t index_of_period = filename.find('.');

	if (index_of_period == std::string::npos) {
		throw std::exception("Error: Incompatible arguments. Must supply a filename and a mode.");
	}
	else if (filename.substr(index_of_period + 1).compare("bf") != 0) {
		throw std::exception("Error: Incorrect type of file passed. Files extension must be \".bf\".");
	}
	else
		return;
}

/*
 * Whelp, I made one method to assert my will and then couldn't stop myself.
 * This one ensures that enough arguments have been passed.
 */
void check_arg_size(int argc) {
	if (argc < 2)
		throw std::exception("Error: not enough arguments passed.");
	else
		return;
}

/*
 * Determines the mode passed. If no argument supplied for this, will default to mode 1.
 */
int get_mode(int argc, char **argv) {
	if (argc == 2)
		return 1;

	int mode = *argv[2] - '0';
	if (mode < 1 || mode > 2)
		throw std::exception("Error: Mode must be 1 or 2.");
	else
		return *argv[2] - '0';
}
