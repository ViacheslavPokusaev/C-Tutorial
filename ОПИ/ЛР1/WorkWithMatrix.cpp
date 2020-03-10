#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <windows.h>

#include "Matrix.h"
#include "WorkWithMatrix.h"

using namespace std;

void Main_algorithm(Matrix matrix)
{
	if (matrix.rows == -1) {
		cout << "Проверьте правильность своей работы!!!\n\n"; system("pause"); return;
	}

	bool end = true;
	int i = 0;

	while (end)
	{
		Change_array(matrix, i);
		if (++i == matrix.columns) { end = false; cout << endl; }
	}

	system("color 02");
	cout << "Matrix has changed successfully\n\n";
	system("pause");
	system("color 07");
}

void Change_array(Matrix matrix, int current_column)
{
	int count = 0, Max = 0;
	string str1, str2;
	float average = 0;

	for (int i = 0, j = matrix.rows - 1; i < matrix.rows; i++, j--)
	{
		str1 += matrix.array[i][current_column] + '0';
		str2 += matrix.array[j][current_column] + '0';
		if (matrix.array[i][current_column] % 2 != 0) { average += matrix.array[i][current_column]; count++; }
	}

	count != 0 && str1 == str2 ?
		Change_polidrom(matrix, current_column, average /= count) :
		Change_other_array(matrix, current_column, str2);
}

void Change_polidrom(Matrix matrix, int current_column, float avr)
{
	int Max = 0;

	for (int i = 0; i < matrix.rows; i++)
		if (Max <= matrix.array[i][current_column])
			Max = matrix.array[i][current_column];

	for (int i = 0; i < matrix.rows; i++)
		if (matrix.array[i][current_column] == Max)
			matrix.array[i][current_column] = avr;
}

void Change_other_array(Matrix matrix, int current_column, string str)
{
	for (int i = 0; i < matrix.rows; i++)
		matrix.array[i][current_column] = str[i] - '0';
}