#include "Matrix.h"
#include <cstddef>
#include <iostream>
#include <iomanip>
using namespace std;

Matrix::Matrix()
{
	Rows = Columns = 0;
	items = NULL;
}
Matrix::~Matrix()
{
	this->ClearRam();
}

void Matrix::SetRows()
{
	int Rows;

	bool temp = false;
	do {
		cout << "Enter rows: ";
		if (!(cin >> Rows) || (Rows < 0))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else temp = true;
	} while (temp == false);

	this->Rows = Rows;
}
void Matrix::SetColumns()
{
	int Columns;

	bool temp = false;
	do {
		cout << "Enter columns: ";
		if (!(cin >> Columns) || (Columns < 0))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else temp = true;
	} while (temp == false);

	this->Columns = Columns;
}
void Matrix::SetItemsByUser()
{
	this->CreateMatrix();

	// Заполнение двумерного массива
	for (int i = 0; i < Rows; i++)
		for (int j = 0; j < Columns; j++)
		{
			cout << "Enter in matrix [" << i << "][" << j << "] = ";  cin >> items[i][j];
		}
}
int Matrix::GetColumns()
{
	return Columns;
}
int Matrix::GetRows()
{
	return Rows;
}
int** Matrix::GetItems()
{
	return items;
}

void Matrix::ShowItems()
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
			cout << setw(6) << setprecision(3) << items[i][j] << " ";
		cout << endl;
	}
}
void Matrix::ClearRam()
{
	for (int i = 0; i < Rows; i++)
		delete[] items[i];
	delete items;
}