#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <windows.h>

#include "Matrix.h"
#include "InputOutput.h"
#include "WorkWithMatrix.h"

using namespace std;

void main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));

	Matrix matrix;
	char option, optionExit;

	try
	{
		do
		{
			printf("\nYou open programm 'question-answer'!\nDo you want to continue? (Y / N) \n");
			cin >> optionExit;
			if ((optionExit == 'Y') || (optionExit == 'y'))
			{
				matrix.Create_array();

				printf("\nDo you want input data from keyboard ? (Y / N) \n");
				cin >> option;

				if ((option == 'Y') || (option == 'y'))
				{
					matrix.User_Fill();
				}
				else 
				{
					printf("\nDo you want fill data with RANDOM ? (Y / N) \n");
					cin >> option;
					
					if ((option == 'Y') || (option == 'y'))
					{
						matrix.Random_Fill();
					}
					else break;
				}

				printf("\nDo you want start algorithm ? (Y / N) \n");
				cin >> option;

				if ((option == 'Y') || (option == 'y'))
				{
					Main_algorithm(matrix);

					printf("\nShow matrix ? (Y / N) \n");
					cin >> option;

					if ((option == 'Y') || (option == 'y'))
					{
						matrix.Show_array();
					}
				}
				else break;
			}
		} while ((optionExit != 'N') && (optionExit != 'n'));
	}
	catch (const std::exception&)
	{
		cout << "Error!!!"; system("pause");
	}

	matrix.Delete();

	cout << "!Program has finished successfully!\n\n";
	system("pause");
}