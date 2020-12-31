#include "repl.h"

int main(int argc, char **argv)
{
    if (argc == 2)
        once(argv[1]);
    else
        repl();

    return 0;
}