#include <iostream>
#include <iomanip>
#include "Apartament.h"
#include "Functional.h"

using namespace std;

Real_estate_float Set_dannie(Real_estate_float object) // Добавление новых квартир
{
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
	return object;
}

void Get_dannie(Real_estate_float object[], int Current_position) // Вывод списка всех квартир
{
	for (int i = 0; i < Current_position; i++)
	{
		cout << "Квартира №" << i + 1 << endl;
		cout << "Фамилия и инициалы владельца: " << object[i].FIO << endl;
		cout << "Адресс квартиры: " << object[i].Address.Street << endl;
		cout << "Номер дома: " << object[i].Address.Number_house << endl;
		cout << "Номер квартиры: " << object[i].Address.Number_float << endl;
		cout << "Цена на квартиру: " << object[i].Price << " $" << endl << endl;
	}
}

void Search_float_for_price(Real_estate_float object[], float price, int current_position) // Поиск квартиры по цене
{
	int temp = 0;
	cout << endl << "---> КВАРТИРЫ ПО ВАШЕМУ ЗАПРОСУ <---" << endl;
	for (int i = 0; i < current_position; i++)
	{
		if (object[i].Price == price)
		{
			cout << "\nФамилия и инициалы владельца: " << object[i].FIO << endl;
			cout << "Адресс квартиры: " << object[i].Address.Street << endl;
			cout << "Номер дома: " << object[i].Address.Number_house << endl;
			cout << "Номер квартиры: " << object[i].Address.Number_float << endl;
		}
		else temp++;
		if (temp == 0)
			cout << "ИЗВИНИТЕ, по вашему запросу ничего не найдено!" << endl;
	}
}

void Minimum_price_on_float(Real_estate_float object[], int current_position) // Вывод списка квартир, которые имеют минимальную цену
{
	int min = object[0].Price;
	cout << endl << "---> КВАРТИРЫ МИНИМАЛЬНЫЕ ПО ЦЕНЕ <---" << endl;
	for (int i = 1; i < current_position; i++)
		if (object[i].Price < min)
			min = object[i].Price;
	for (int i = 0; i < current_position; i++)
	{
		if (object[i].Price == min)
		{
			cout << "\nФамилия и инициалы владельца: " << object[i].FIO << endl;
			cout << "Адресс квартиры: " << object[i].Address.Street << endl;
			cout << "Номер дома: " << object[i].Address.Number_house << endl;
			cout << "Номер квартиры: " << object[i].Address.Number_float << endl;
			cout << "Цена на квартиру: " << object[i].Price << " $" << endl << endl;
		}
	}
}

void Information_about_name_float(Real_estate_float object[], int current_position) // Поиск конкретной квартиры
{
	char Street[100]; int Number_house, Number_float; bool temp = false;
	cin.get();
	cout << "Введите адресс квартиры >>> ";
	cin.getline(Street, 100);
	// Защита от неправильного ввода данных
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

	// Поиск нужной квартиры
	bool search = false;
	cout << "\n---> Результат поиска <---" << endl << endl;
	for (int i = 0; !search && i < current_position; i++)
		if (strcmp(Street, object[i].Address.Street) == 0 && Number_float == object[i].Address.Number_float && Number_house == object[i].Address.Number_house)
		{
			cout << "Фамилия и инициалы владельца: " << object[i].FIO << endl;
			cout << "Цена на квартиру: " << object[i].Price << " $" << endl << endl;
			search = true;
		}
	if (search == false) cout << "!Квартира не найдена!" << endl;
}

void Sort_struct(Real_estate_float object[], int vibor, int current_position) // Сортировка квартир по возрастании или спаданию
{
	bool t = true;
	if (vibor == 1)
	{	// соритировка по возрастанию
		while (t)
		{
			t = false;
			for (int i = 0; i < current_position - 1; i++)
			{
				for (int j = 0; j < current_position - i - 1; j++)
					if (object[j].Price > object[j + 1].Price)
					{
						swap(object[j], object[j + 1]);
						t = true;
					}
			}
		}
	}
	else
	{	// соритировка по спаданию
		t = false;
		for (int i = 0; i < current_position - 1; i++)
		{
			for (int j = 0; j < current_position - i - 1; j++)
				if (object[j].Price < object[j + 1].Price)
				{
					swap(object[j], object[j + 1]);
					t = true;
				}
		}
	}
}