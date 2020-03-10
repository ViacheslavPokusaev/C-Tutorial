#include <iostream>
#include <iomanip>
#include "Apartament.h"
#include "Functional.h"

using namespace std;

Real_estate_float Set_dannie(Real_estate_float object) // ���������� ����� �������
{
	float Price; int Number_house, Number_float;
	cin.get();
	cout << "������� ������� � �������� ��������� >>> "; cin.getline(object.FIO, 50);
	cout << "������� ������ �������� >>> "; cin.getline(object.Address.Street, 100);
	// ������ ������ �� ������������� �����
	bool temp = false;
	do {
		cout << "������� ����� ���� >>> ";
		if (!(cin >> Number_house) || (Number_house < 0))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else temp = true;
	} while (temp == false);
	temp = false;
	do {
		cout << "������� ����� �������� >>> ";
		if (!(cin >> Number_float) || (Number_float < 0))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else temp = true;
	} while (temp == false);
	temp = false;
	do {
		cout << "������� ���� >>> ";
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

void Get_dannie(Real_estate_float object[], int Current_position) // ����� ������ ���� �������
{
	for (int i = 0; i < Current_position; i++)
	{
		cout << "�������� �" << i + 1 << endl;
		cout << "������� � �������� ���������: " << object[i].FIO << endl;
		cout << "������ ��������: " << object[i].Address.Street << endl;
		cout << "����� ����: " << object[i].Address.Number_house << endl;
		cout << "����� ��������: " << object[i].Address.Number_float << endl;
		cout << "���� �� ��������: " << object[i].Price << " $" << endl << endl;
	}
}

void Search_float_for_price(Real_estate_float object[], float price, int current_position) // ����� �������� �� ����
{
	int temp = 0;
	cout << endl << "---> �������� �� ������ ������� <---" << endl;
	for (int i = 0; i < current_position; i++)
	{
		if (object[i].Price == price)
		{
			cout << "\n������� � �������� ���������: " << object[i].FIO << endl;
			cout << "������ ��������: " << object[i].Address.Street << endl;
			cout << "����� ����: " << object[i].Address.Number_house << endl;
			cout << "����� ��������: " << object[i].Address.Number_float << endl;
		}
		else temp++;
		if (temp == 0)
			cout << "��������, �� ������ ������� ������ �� �������!" << endl;
	}
}

void Minimum_price_on_float(Real_estate_float object[], int current_position) // ����� ������ �������, ������� ����� ����������� ����
{
	int min = object[0].Price;
	cout << endl << "---> �������� ����������� �� ���� <---" << endl;
	for (int i = 1; i < current_position; i++)
		if (object[i].Price < min)
			min = object[i].Price;
	for (int i = 0; i < current_position; i++)
	{
		if (object[i].Price == min)
		{
			cout << "\n������� � �������� ���������: " << object[i].FIO << endl;
			cout << "������ ��������: " << object[i].Address.Street << endl;
			cout << "����� ����: " << object[i].Address.Number_house << endl;
			cout << "����� ��������: " << object[i].Address.Number_float << endl;
			cout << "���� �� ��������: " << object[i].Price << " $" << endl << endl;
		}
	}
}

void Information_about_name_float(Real_estate_float object[], int current_position) // ����� ���������� ��������
{
	char Street[100]; int Number_house, Number_float; bool temp = false;
	cin.get();
	cout << "������� ������ �������� >>> ";
	cin.getline(Street, 100);
	// ������ �� ������������� ����� ������
	do {
		cout << "������� ����� ���� >>> ";
		if (!(cin >> Number_house) || (Number_house < 0))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else temp = true;
	} while (temp == false);
	temp = false;
	do {
		cout << "������� ����� �������� >>> ";
		if (!(cin >> Number_float) || (Number_float < 0))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else temp = true;
	} while (temp == false);

	// ����� ������ ��������
	bool search = false;
	cout << "\n---> ��������� ������ <---" << endl << endl;
	for (int i = 0; !search && i < current_position; i++)
		if (strcmp(Street, object[i].Address.Street) == 0 && Number_float == object[i].Address.Number_float && Number_house == object[i].Address.Number_house)
		{
			cout << "������� � �������� ���������: " << object[i].FIO << endl;
			cout << "���� �� ��������: " << object[i].Price << " $" << endl << endl;
			search = true;
		}
	if (search == false) cout << "!�������� �� �������!" << endl;
}

void Sort_struct(Real_estate_float object[], int vibor, int current_position) // ���������� ������� �� ����������� ��� ��������
{
	bool t = true;
	if (vibor == 1)
	{	// ����������� �� �����������
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
	{	// ����������� �� ��������
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