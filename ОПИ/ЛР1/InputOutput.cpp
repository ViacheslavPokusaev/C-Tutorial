#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <windows.h>

#include "InputOutput.h"

using namespace std;

char User_Menu() // Мeню пользователя
{
	// Выбранный вариант меню
	char choice;
	bool right_choice = false;

	system("cls");
	cout << "\tМЕНЮ\n";
	cout << "'1' - Создание матрицы\n";
	cout << "'2' - Заполнение матрицы\n";
	cout << "'3' - Работа с матрицей\n";
	cout << "'4' - Вывод матрицы\n";
	cout << "'5' - Очистка памяти (Удаление матрицы)\n";
	cout << "'6' - Выход\n\n";

	// Защита от неправильного ввода пункта меню
	while (!right_choice)
	{
		cout << "Ваш выбор >>> "; cin >> choice;

		for (int i = 1; i <= 6; i++)
		{
			if (choice == (i + '0'))
			{
				right_choice = true; break;
			}
		}

		if (!right_choice) {
			system("color 04");
			cout << "Такого пункта меню не существует! Проверьте правильность ввода!" << endl;
			system("pause");
			system("color 07");
			User_Menu();
		}
	}

	system("cls");
	return choice;
}

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