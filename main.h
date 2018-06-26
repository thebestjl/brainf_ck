#pragma once
#include "bf_interpreter.h"

void parse_filename(std::string filename);
void check_arg_size(int argc);
int get_mode(int argc, char **argv);