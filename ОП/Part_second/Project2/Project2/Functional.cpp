#include <fstream>
#include <iostream>
#include "Apart.h"
#include "Functional.h"

void Set_dannie(ofstream& out) // Добавление новых квартир
{
	Real_estate_float object;
	float Price; int Number_house, Number_float;
	cin.get();
	cout << "Введите фамилию и инициалы владельца >>> "; cin.getline(object.FIO, 50);
	cout << "Введите адресс квартиры >>> "; cin.getline(object.Address.Street, 100);
	// Защита данных от неправильного ввода
	bool temp = false;
	do {
		cout << "Введите номер дома >>> ";
		if (!(cin >> Number_house) || (Number_house < 0))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else temp = true;
	} while (temp == false);
	temp = false;
	do {
		cout << "Введите номер квартиры >>> ";
		if (!(cin >> Number_float) || (Number_float < 0))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else temp = true;
	} while (temp == false);
	temp = false;
	do {
		cout << "Введите цену >>> ";
		if (!(cin >> Price) || (Price < 0))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else temp = true;
	} while (temp == false);
	object.Address.Number_house = Number_house;
	object.Address.Number_float = Number_float;
	object.Price = Price;
	cin.get();
	
	out.write((char*)&object, sizeof(object));	
}

void Get_data(Real_estate_float f[], int size_array, ifstream& in)
{
	for (int i = 0; i < size_array; i++)
	{
		in.read((char*)&f[i], sizeof(Real_estate_float));

		cout << "Квартира №" << i + 1 << endl;
		cout << "Фамилия и инициалы владельца: " << f[i].FIO << endl;
		cout << "Адресс квартиры: " << f[i].Address.Street << endl;
		cout << "Номер дома: " << f[i].Address.Number_house << endl;
		cout << "Номер квартиры: " << f[i].Address.Number_float << endl;
		cout << "Цена на квартиру: " << f[i].Price << " $" << endl << endl;
	}
	in.close();
}