#include <iostream>
#include <windows.h>
#include <iomanip>
#include "Matrix.h"
using namespace std;


void Matrix::Create_array()
{
	Matrix::Delete();

	cout << "Enter cout rows: "; cin >> rows;
	cout << "Enter cout columns: "; cin >> columns;

	// Create Matrix
	array = new int* [rows];
	for (int count = 0; count < rows; count++)
		array[count] = new int[columns];

	system("color 02");
	cout << "\nMatrix was builted successfully\n\n";
	system("pause");
	system("color 07");
}

void Matrix::Random_Fill()
{
	for (int count_row = 0; count_row < rows; count_row++)
		for (int count_column = 0; count_column < columns; count_column++)
			array[count_row][count_column] = (rand() % 4) + 1;

	system("color 02");
	cout << "Matrix has filled successfully\n\n";
	system("pause");
	system("color 07");
}

void Matrix::User_Fill()
{
	for (int count_row = 0; count_row < rows; count_row++)
		for (int count_column = 0; count_column < columns; count_column++)
		{
			cout << "Array[" << count_row << "][" << count_column << "]: ";
			cin >> array[count_row][count_column];
		}

	system("color 02");
	cout << "Matrix has filled successfully\n\n";
	system("pause");
	system("color 07");
}

void Matrix::Show_array()
{
	system("cls");
	cout << "Array (rows - " << rows << ", columns - " << columns << ")\n\n";

	for (int count_row = 0; count_row < rows; count_row++)
	{
		for (int count_column = 0; count_column < columns; count_column++)
			cout << setw(4) << setprecision(2) << array[count_row][count_column] << "   ";
		cout << endl;
	}

	cout << endl;
	system("pause");
}

void Matrix::Delete()
{
	for (int i = 0; i < rows; i++)
		delete[] array[i];
	delete[] array;
	rows = columns = -1;
}