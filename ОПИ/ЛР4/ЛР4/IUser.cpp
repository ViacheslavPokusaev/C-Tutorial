#include "IUser.h"
using namespace std;

IUser::IUser()
{
	matrix = new Matrix();
	matrixAlgorithms = new MatrixAlgorithms();
}
IUser::~IUser()
{
	delete matrix;
	delete matrixAlgorithms;
}

void IUser::Menu()
{
	int variant;

	do
	{
		do
		{
			system("cls");
			cout << "\tMENU\n" << endl;
			cout << "1. Create matrix\n"
				<< "2. Fill matrix\n"
				<< "3. Show matrix\n"
				<< "4. Search vertical coincidance\n"
				<< "5. Search gorizontal coincidance\n"
				<< "6. Exit\n";
			cout << "Your choice >>> ";
			if (!(cin >> variant) || (variant < 1 || variant > 6)) {
				system("cls");
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while (variant < 1 || variant > 7);

		switch (variant) {
		case 1:
		{
			system("cls");
			cout << "---> CREATING <---\n\n";

			matrix->SetRows();
			matrix->SetColumns();

			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			cout << "---> FILLING <---\n\n";

			matrix->SetItemsByUser();

			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "--->SHOWING <---\n\n";

			matrix->ShowItems();

			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "---> VERTICAL COINS <---\n\n";

			matrixAlgorithms->SearchCoincidences(variant, matrix);

			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			cout << "---> GORIZONTAL COINS <---\n\n";

			matrixAlgorithms->SearchCoincidences(variant, matrix);

			system("pause");
			break;
		}

		}
	} while (variant != 6);

	this->~IUser();
}
