#ifndef BF_H_
#define BF_H_

#include <iostream>
#include <stack>

const int MEM_SIZE = 32;

struct memory
{
    int mem[MEM_SIZE];    // memory size
    int loc;              // ptr location
};

// display all the values in the mem and the ptr location
void show_mem(memory *m)
{
    std::cout << "MEM: ";
    for (int i : m->mem)
        std::cout << i << " ";
    std::cout << "\nPTR: " << m->loc << std::endl;
}

// perform action
int step(memory *m, char inst)
{
    char n;
    switch (inst)
    {
    case '>':
        (m->loc)++;
        break;
    case '<':
        (m->loc)--;
        break;
    case '+':
        (m->mem)[m->loc]++;
        break;
    case '-':
        (m->mem)[m->loc]--;
        break;
    case '[':
        return 1;
        break;
    case ']':
        if ((m->mem)[m->loc])
            return 2;
        return 3;
        break;
    case '.':
        n = (m->mem)[m->loc];
        std::cout << n;
        break;
    case ',':
        std::cin >> n;
        (m->mem)[m->loc] = n;
    default:
        break;
    }
    return 0;
}

// interpret program
void exec(memory *m, std::string insts)
{
    std::stack<int> loops;
    int pin = 0;

    while (pin < insts.size())
    {
        int result = step(m, insts[pin]);
        switch (result)
        {
        case 1:
            loops.push(pin);        // loop start
            break;
        case 2:
            pin = loops.top();      // continue loop
            break;
        case 3:
            loops.pop();            // jump out of loop
            break;
        default:
            break;
        }
        pin++;
    }
}

#endif