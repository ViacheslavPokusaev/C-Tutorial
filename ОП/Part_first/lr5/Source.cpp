//----------// �������� ��������� �� ��������� ������� ������� //----------//
// ����� ���: 
// - ������ ������� - ϲ� �������� �������� FIO �� ������ �������� Street, 
// - ��� ����� - ����� ������� Street, ����� �������� Number_float, ���� ������ ���� vibor,
// - ����� ����� - ���� �������� Price
// ������ ���: 
// - ������ ��� �������
// - ������ ������� ������� ����
// - ������ ������� � ��������� �����
// - ���������� ��� ������� �������� � ������
// - ������������ ������ �������

#include <iostream>
#include <iomanip>
#include "Apartament.h"
#include "Functional.h"
#define Size_struct 5 // ������ �������
using namespace std;

int Menu_user() // �e�� ������������
{
	// ��������� ������� ����
	int variant;
	do {
		system("cls");
		cout << "\t����\n" << endl;
		cout << "1. �������� ��������\n"
			<< "2. ������� ���� ������ �������\n"
			<< "3. ������� ������ ������� �� ��������� �����\n"
			<< "4. �������� � ������������ ������\n"
			<< "5. ����� �������� �� ��������� ��������\n"
			<< "6. ���������� ������� �� ������\n"
			<< "7. ����� � ���������\n" << endl;
		cout << "��� ����� >>> ";
		// ������ �� ������������� ����� ������ ����
		if (!(cin >> variant) || (variant < 1 || variant > 7)) {
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (variant < 1 || variant > 7);
	return variant;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int Current_position_index_struct = 3;

	Real_estate_float fl[Size_struct] // �������� ��������� �������� �� 5 ���������
	{
		{ "�������� �������� ����������", "c. Dnipro, d. Topol - 1", 6, 44, 30000 },
		{ "���������� ���� ���������", "c. Dnipro, d. Petrovskiy", 56, 1, 10000},
		{ "������� ���� ���������", "c. Dnipro, d. Leftbeach - 3", 77, 777, 12500 }
	};

	int variant = Menu_user();

	do
	{
		switch (variant) {
		case 1:
		{
			system("cls");
			cout << "---> ���������� ����� �������� <---\n\n";
			if (Current_position_index_struct <= 5) // �������� �� ������ �������
			{
				fl[Current_position_index_struct] = Set_dannie(fl[Current_position_index_struct]);
				Current_position_index_struct++;
				cout << "---> �������� ��������� <---\n";
			}
			else cout << "!��������� ����������! ���������� ����� ������� ����������!" << endl;
			system("pause");
			variant = Menu_user();
			break;
		}
		case 2:
		{
			system("cls");
			Get_dannie(fl, Current_position_index_struct);
			system("pause");
			variant = Menu_user();
			break;
		}
		case 3:
		{
			bool metka = false;
			float price;
			do {
				system("cls");
				cout << "---> ����� �������� �� ����� <---\n\n" << "������� ���� >>> ";
				if (!(cin >> price) || (price < 0))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else metka = true;
			} while (metka == false);
			Search_float_for_price(fl, price, Current_position_index_struct);
			system("pause");
			variant = Menu_user();
			break;
		}
		case 4:
		{
			system("cls");
			Minimum_price_on_float(fl, Current_position_index_struct);
			system("pause");
			variant = Menu_user();
			break;
		}
		case 5:
		{
			system("cls");
			Information_about_name_float(fl, Current_position_index_struct);
			system("pause");
			variant = Menu_user();
			break;
		}
		case 6:
		{
			system("cls");
			int temp;
			do {
				system("cls");
				cout << "---> ���������� <---\n\n" << "1 - ����������� �������� �� ������������\n" << "2 - ����������� �������� �� ��������\n" << "��� ����� >>> ";
				if (!(cin >> temp) || (temp < 1 || temp > 2)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			} while (temp < 1 || temp > 2);
			Sort_struct(fl, temp, Current_position_index_struct);
			cout << "\n�������� �������������!" << endl;
			system("pause");
			variant = Menu_user();
			break;
		}
		case 7:
			exit(EXIT_SUCCESS);
			break;
		}
	} while (variant != 7);

	return 0;
}