#include "MatrixAlgorithms.h"
#include <cstddef>

MatrixAlgorithms::MatrixAlgorithms() 
{
	Indexs = NULL;
	Length = 0;
}
MatrixAlgorithms::~MatrixAlgorithms()
{
	this->ClearRam();
}

void  MatrixAlgorithms::ClearRam()
{
	delete Indexs;
}
void MatrixAlgorithms::SetIndexs(int Size)
{
	this->ClearRam();

	Indexs = new int[Size];
}
void MatrixAlgorithms::ShowCoincidences(int Item, int RowOrColumn, int TypeCoincidence)
{
	if (TypeCoincidence % 2 != 0)
	{
		cout << "\n!Gorizontal coincidences!" << endl;
		cout << "Item - " << Item << endl;
		cout << "Row index - " << RowOrColumn << endl;
		cout << "Column's indexs - ";

		for (int i = 0; i <= Length; i++)
		{
			cout << Indexs[i] << " ";
		}
	}
	else
	{
		cout << "\n!Vertical coincidences!" << endl;
		cout << "Item - " << Item << endl;
		cout << "Column index - " << RowOrColumn << endl;
		cout << "Row's indexs - ";

		for (int i = 0; i <= Length; i++)
		{
			cout << Indexs[i] << " ";
		}
	}

	cout << endl;
}
void MatrixAlgorithms::SearchCoincidences(int TypeCoincidence, Matrix* matrix)
{
	int currentCoincidence, Rows = matrix->GetRows(), Columns = matrix->GetColumns();
	int** items = matrix->GetItems();

	if (TypeCoincidence % 2 == 0)
	{
		this->SetIndexs(Rows);

		for (int j = 0; j < Columns; j++)
		{
			for (int i = Rows - 1; i >= 0; --i)
				if (i - 1 >= 0)
				{
					if (items[i][j] == items[i - 1][j])
					{
						currentCoincidence = items[i][j];
						Indexs[Length] = i;
						Indexs[++Length] = i - 1;
					}
					else if (Length != 0) {
						ShowCoincidences(currentCoincidence, j, TypeCoincidence);
						Length = currentCoincidence = 0;
						Indexs = new int[Rows];
					}
				}

			if (Length != 0)
			{
				ShowCoincidences(currentCoincidence, j, TypeCoincidence);
			}

			Length = currentCoincidence = 0;
			Indexs = new int[Rows];
		}
	}
	else
	{
		this->SetIndexs(Columns);

		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
				if (items[i][j] == items[i][j + 1] && ((j + 1) < Columns))
				{
					currentCoincidence = items[i][j];
					Indexs[Length] = j; // заполняем матрицу индексами, где было совпадение
					Indexs[++Length] = j + 1;
				}
			// когда совпадений в строке не найдены, начинаем всё по новой
				else if (Length != 0) {
					ShowCoincidences(currentCoincidence, i, TypeCoincidence);
					Length = currentCoincidence = 0;
					Indexs = new int[Columns];
				}

			if (Length != 0)
			{
				ShowCoincidences(currentCoincidence, i, TypeCoincidence);
			}

			Length = currentCoincidence = 0;
			Indexs = new int[Columns];
		}		
	}

	cout << endl << endl << " ----- " << endl << endl;
}