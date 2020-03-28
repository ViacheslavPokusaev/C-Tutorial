#include <windows.h>
#include <iostream>
#include "InputOutput.h"
using namespace std;

char User_Menu()
{
	char choice;
	bool right_choice = false;

	system("cls");
	cout << "\tMENU\n";
	cout << "'1' - Open File\n";
	cout << "'2' - Read File\n";
	cout << "'3' - Change and save changes in other file\n";
	cout << "'4' - Exit\n\n";

	while (!right_choice)
	{
		cout << "Chose right opinion >>> "; cin >> choice;

		for (int i = 1; i <= 4; i++)
		{
			if (choice == (i + '0'))
			{
				right_choice = true; break;
			}
		}

		if (!right_choice) {
			system("color 04");
			cout << "Your choise is wrong, please repeat input choise again!" << endl;
			system("pause");
			system("color 07");
			User_Menu();
		}
	}

	system("cls");
	return choice;
}