#ifndef REPL_H_
#define REPL_H_

#include <iostream>
#include <fstream>
#include "bf.h"

// run bf file
void once(char *input)
{
    int *bm = new int[MEM_SIZE];
    for (int i = 0; i < MEM_SIZE; i++)
        bm[i] = 0;
    memory m = {*bm, 0};

    // read the whole file at once
    // Solution from: https://stackoverflow.com/q/18816126/10499685
    auto getFileContent = [](const std::string &path) -> std::string {
        std::ifstream file(path);
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

        return content;
    };

    std::string line = getFileContent(input);
    exec(&m, line);
}

// the bf repl
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