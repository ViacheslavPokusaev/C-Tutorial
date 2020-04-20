#include<iostream>
#include<fstream>
#include "Float.h"
#include "JobWithFile.h"

using namespace std;

int main()
{
	ofstream out;
	ifstream in;
	int CountRecordsInFile = 3;
	Real_estate_float _float; // For record in file
	char* NameFile = new char[200];
	int choiseUser; // Menu
	bool check = false;

	/*out.open("test.dat", ios::binary | ios::app | ios::trunc);
	Real_estate_float floats[3] = {
		{ "pokusaev vyacheslav oleksiyovich", "c. dnipro, d. topol - 1", 6, 44, 30000 },
		{ "kostychdenko mark oleg", "c. dnipro, d. petrovskiy", 56, 1, 30000},
		{ "guzenko artem artemovich", "c. dnipro, d. leftbeach - 3", 77, 777, 12500 }
	};
	out.write(static_cast <char*>(static_cast <void*> (floats)), sizeof floats);
	out.close();*/

	while (true)
	{
		system("cls");
		cout << "\tMenu\n\n";
		cout << "1. Open file\n"
			<< "2. Add float\n"
			<< "3. Show all floats\n"
			<< "4. Search floats by price\n"
			<< "5. Search the lowest floats\n"
			<< "6. Exit\n\n";

		cout << "Your choise: "; cin >> choiseUser;

		switch (choiseUser)
		{
		case 1:
		{
			cout << "Enter name file: "; cin >> NameFile;
			CheckFile(out, NameFile);
			in.open(NameFile, ios::binary | ios::in);
			check = true;
			system("pause");
			break;
		}
		case 2:
		{
			if (check)
			{
				cout << "Add data to float:\n";
				cout << "FIO: "; cin >> _float.FIO;
				cout << "Number_float: "; cin >> _float.Address.Number_float;
				cout << "Number_house: "; cin >> _float.Address.Number_house;
				cout << "Street: "; cin >> _float.Address.Street;
				AddToFile(out, _float, CountRecordsInFile);
			}
			else
				cout << "You shoud open file! Please choise 1 opinion\n";
			system("pause");
			break;
		}
		case 3:
		{
			if (check)
				ReadAllFromFile(in, CountRecordsInFile);
			else
				cout << "You shoud open file! Please choise 1 opinion\n";
			system("pause");
			break;
		}
		case 4:
		{
			if (check)
				ShowFloatWithDefinitelyPrice(in, CountRecordsInFile);
			else
				cout << "You shoud open file! Please choise 1 opinion\n";
			system("pause");
			break;
		}
		case 5:
		{
			if (check)
				ShowLowFloats(in, CountRecordsInFile);
			else
				cout << "You shoud open file! Please choise 1 opinion\n";
			system("pause");
			break;
		}
		case 6:
			exit(EXIT_SUCCESS);
			break;
		default:
			break;
		}
	}

	out.close();
	in.close();

	system("pause");
	return 0;
}