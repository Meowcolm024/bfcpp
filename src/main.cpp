#include <iostream>
#include <fstream>
#include "bf.h"

using namespace std;

int main()
{
	int bm[MEM_SIZE];
	memory m;

	while (true) {
		for (int i = 0; i < MEM_SIZE; i++)
			bm[i] = 0;
		m = {*bm, 0};

		cout << "> ";
		string input;
		cin >> input;

		if (input == "q")
			break;
		else
			exec(&m, input);
	}

	return 0;
}