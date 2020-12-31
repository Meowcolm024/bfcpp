#ifndef REPL_H_
#define REPL_H_

#include <iostream>
#include <fstream>
#include "bf.h"

void once(char* input)
{
    int *bm = new int[MEM_SIZE];
    for (int i = 0; i < MEM_SIZE; i++)
        bm[i] = 0;
    memory m = {*bm, 0};

    std::ifstream myfile(input);
    std::string line;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
            exec(&m, line);
        myfile.close();
    }
}

void repl()
{
    int *bm = new int[MEM_SIZE];
    memory m;
    std::cout << "bfcpp\n";
    while (std::cin)
    {
        for (int i = 0; i < MEM_SIZE; i++)
            bm[i] = 0;
        m = {*bm, 0};

        std::cout << "> ";
        std::string input;
        std::cin >> input;
        exec(&m, input);
    }
}

#endif