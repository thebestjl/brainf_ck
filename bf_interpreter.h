#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class bf {
private:
	const static int MAX_SIZE = 510000;

	static void initialize(char *data, int *loop);
	static std::string read_input(std::string);
	
public:
	static void interpret(const std::string src);
	static void interpret_no_ptrs(const std::string src);
};