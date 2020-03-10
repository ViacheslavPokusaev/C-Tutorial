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
	char option;

	try
	{
		do
		{
			option = User_Menu();

			switch (option)
			{
			case '1':
				matrix.Create_array();
				break;
			case '2':
				if (Fill_array())
					matrix.User_Fill();
				else matrix.Random_Fill();
				break;
			case '3':
				Main_algorithm(matrix);
				break;
			case '4':
				matrix.Show_array();
				break;
			case '5':
				matrix.Delete();
				break;
			case '6':
				break;
			default:
				break;
			}

		} while (option != '6');
	}
	catch (const std::exception&)
	{
		cout << "Проверьте правильность своей работы!!!"; system("pause");
	}
	
	cout << "!Program has finished successfully!\n\n";
	system("pause");
}