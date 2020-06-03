#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <windows.h>

#include "InputOutput.h"

using namespace std;

bool Fill_array()
{
	int Answer = -1;

	while (Answer != 1 && Answer != 2)
	{
		cout << "Do you want input yourself matrix? (Yes - 1, No - 2) --> ";
		cin >> Answer;
		if (Answer != 1 && Answer != 2) {
			system("color 04"); cout << "Error! Try to input data again!" << endl; system("color 07"); system("pause");
		}
	}

	if (Answer == 1) return true; else return false;
}