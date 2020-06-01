#include<iostream>
#include <iomanip>
#include <ctime>
#include<Windows.h>

using namespace std;

struct Matrix {
	int Rows, Colums;
	int** items; // массив указателей
};

void CreateMatrix(Matrix& matrix)
{
	cout << "Enter rows: "; cin >> matrix.Rows;
	cout << "Enter colums: "; cin >> matrix.Colums;

	// Создание двумерного массива (массива указателей)
	matrix.items = new int* [matrix.Rows];
	for (int i = 0; i < matrix.Rows; i++)
		matrix.items[i] = new int[matrix.Colums];

	// Заполнение двумерного массива
	for (int i = 0; i < matrix.Rows; i++)
		for (int j = 0; j < matrix.Colums; j++)
		{
			cout << "Enter in matrix [" << i << "][" << j << "] = ";  cin >> matrix.items[i][j];
		}
}

void ShowMatrix(Matrix& matrix)
{
	for (int i = 0; i < matrix.Rows; i++)
	{
		for (int j = 0; j < matrix.Colums; j++)
			cout << setw(6) << setprecision(3) << matrix.items[i][j] << " ";
		cout << endl;
	}
}

void ShowGorizontalCoincidences(int array[], int Length, int Item, int Row)
{
	cout << "\n!Gorizontal coincidences!" << endl;
	cout << "Item - " << Item << endl;
	cout << "Row index - " << Row << endl;
	cout << "Column's indexs - ";

	for (int i = 0; i < Length; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

void ShowVerticalCoincidences(int array[], int Length, int Item, int Column)
{
	cout << "\n!Vertical coincidences!" << endl;
	cout << "Item - " << Item << endl;
	cout << "Column index - " << Column << endl;
	cout << "Rows's indexs - ";

	for (int i = 0; i < Length; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

void ClearRam(Matrix &matrix)
{
	for (int i = 0; i < matrix.Rows; i++)
		delete[] matrix.items[i];
	delete matrix.items;
}

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Matrix matrix{ 0, 0, 0 };
	int* gorizontalIndexs = new int[matrix.Colums];
	int* verticalIndexs = new int[matrix.Rows];
	int Length = 0, currentCoincidence = 0;

	CreateMatrix(matrix);
	ShowMatrix(matrix);

	cout << endl << endl << " ----- " << endl << endl;

	for (int i = 0; i < matrix.Rows; i++)
	{
		for (int j = 0; j < matrix.Colums; j++)
			if (matrix.items[i][j] == matrix.items[i][j + 1] && ((j + 1) < matrix.Colums))
			{
				currentCoincidence = matrix.items[i][j];
				gorizontalIndexs[Length] = j; // заполняем матрицу индексами, где было совпадение
				gorizontalIndexs[++Length] = j + 1;
			}
			// когда совпадений в строке не найдены, начинаем всё по новой
			else if (Length != 0) {
				ShowGorizontalCoincidences(gorizontalIndexs, Length + 1, currentCoincidence, i);
				Length = currentCoincidence = 0;
				gorizontalIndexs = new int[matrix.Colums];
			}

		if (Length != 0)
		{
			ShowGorizontalCoincidences(gorizontalIndexs, Length + 1, currentCoincidence, i);
		}

		Length = currentCoincidence = 0;
		gorizontalIndexs = new int[matrix.Colums];
	}

	cout << endl << endl << " ----- " << endl << endl;

	// меняем местами строки и столбцы
	for (int j = 0; j < matrix.Colums; j++)
	{
		for (int i = matrix.Rows - 1; i >= 0; --i)
			if (i - 1 >= 0)
			{
				if (matrix.items[i][j] == matrix.items[i - 1][j])
				{
					currentCoincidence = matrix.items[i][j];
					verticalIndexs[Length] = i;
					verticalIndexs[++Length] = i - 1;
				}
				else if (Length != 0) {
					ShowVerticalCoincidences(verticalIndexs, Length + 1, currentCoincidence, j);
					Length = currentCoincidence = 0;
					verticalIndexs = new int[matrix.Rows];
				}
			}

		if (Length != 0)
		{
			ShowVerticalCoincidences(verticalIndexs, Length + 1, currentCoincidence, j);
		}

		Length = currentCoincidence = 0;
		verticalIndexs = new int[matrix.Rows];
	}

	ClearRam(matrix);
	delete gorizontalIndexs;
	delete verticalIndexs;

	system("pause");
	return 0;
}