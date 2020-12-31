#include "repl.h"

int main(int argc, char** argv)
{
	if (argc == 2)
		{
			std::string arg = argv[1];
			once(arg);}
	else
		repl();
		
	return 0;
}