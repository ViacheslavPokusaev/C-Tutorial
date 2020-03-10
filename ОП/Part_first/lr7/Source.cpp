#include <iostream>
using namespace std;

int Value_1(double x1, char x2, bool x3)
{
	cout << "�������� �� ��������\n\n";

	cout << "�������� ����������:" << "x1=" << x1 << " x2=" << x2 << " x3=" << x3 << endl;
	if (x2 == 'a' && x3)
		x1++;
	cout << "������� ����������: " << x1 << endl;

	return x1;
}

char Address(int& x1, char& x2, bool& x3)
{
	cout << "�������� �� ������\n\n";

	cout << "�������� ����������:" << "x1=" << x1 << " x2=" << x2 << " x3=" << x3 << endl;
	if (x1 == 1 && !x3)
	{
		cout << "������� ���������� " << x2 << endl;
		return x2;
	}
	else {
		cout << "������� ����������: " << 'q' << endl; return 'q';
	}
}

void Reference(int* x1, char* x2, bool* x3)
{
	cout << "�������� �� ���������\n\n";

	cout << "�������� ����������:" << "x1=" << x1 << " x2=" << x2 << " x3=" << x3 << endl;
	*x1 = *x1 + 1; *x2 = 't'; *x3 = false;
	cout << "�������� ����������:" << "x1=" << x1 << " x2=" << x2 << " x3=" << x3 << endl;

	cout << "������� �� ���������� ��������" << endl;
}

int* Value_2(int x1, char x2, bool x3)
{
	cout << "�������� �� ��������\n\n";

	cout << "�������� ����������:" << "x1=" << x1 << " x2=" << x2 << " x3=" << x3 << endl;
	int* px1 = &x1;
	cout << "������� ����������: " << px1 << endl;

	return px1;
}

char* Value_3(int& x1, char& x2, bool& x3)
{
	cout << "�������� �� ��������\n\n";

	cout << "�������� ����������:" << "x1=" << &x1 << " x2=" << &x2 << " x3=" << &x3 << endl;
	char* px2 = &x2;

	cout << "������� ����������: " << px2 << endl;
	return px2;
}

void Value_array(int array[4])
{
	cout << "�������� �� ��������\n\n";

	cout << "�������� ����������:" << endl;
	for (int i = 0; i < 4; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	cout << "�������� ���������� �����" << endl;
	for (int i = 0; i < 4; ++i)
	{
		array[i] = rand() % 10;
		cout << array[i] << " ";
	}

	cout << endl << "������� �� ���������� ��������" << endl;
}

void Address_array(int(&array)[4])
{
	cout << "�������� �� ������\n\n";

	cout << "�������� ���������� ��: " << endl;
	for (int i = 0; i < 4; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	cout << "�������� ���������� �����" << endl;
	for (int i = 0; i < 4; i++)
	{
		array[i] = -1;
		cout << array[i] << " ";
	}
	cout << endl;

	cout << "������� �� ���������� ��������" << endl;
}

void Reference_array(int* array)
{
	cout << "�������� �� ���������\n\n";

	cout << "�������� ���������� ��: " << endl;
	for (int i = 0; i < 4; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	cout << "�������� ���������� �����" << endl;
	for (int i = 0; i < 6; ++i)
	{
		array[i] = -2;
		cout << array[i] << " ";
	}
	cout << endl;

	cout << "������� �� ���������� ��������" << endl;
}

struct Money
{
	double grivna;
	double euro;
	double dollar;
};

Money Value_struct(Money money)
{
	cout << "�������� �� ��������\n\n";

	cout << "�������� ���������� �� :" << endl;
	cout << money.dollar << " dol., " << money.euro << " euro, " << money.grivna << " grn.\n";

	money.dollar = 0;
	money.euro = 0;
	money.grivna = 0;

	cout << "\n�������� ���������� �����" << endl;
	cout << money.dollar << " dol., " << money.euro << " euro, " << money.grivna << " grn.\n";

	return money;
}

Money* Address_struct(Money& money)
{
	cout << "�������� �� ������\n\n";

	cout << "�������� ���������� �� :" << endl;
	cout << money.dollar << " dol., " << money.euro << " euro, " << money.grivna << " grn.\n";

	money.dollar = 5;
	money.euro = 5;
	money.grivna = 5;
	Money* mn = &money;

	cout << "������� ����������: " << mn << endl;
	return mn;
}

Money& Reference_struct(Money* money)
{
	cout << "�������� �� ���������\n\n";

	cout << "�������� ���������� �� :" << endl;
	cout << money->dollar << " dol., " << money->euro << " euro, " << money->grivna << " grn.\n";

	money->dollar = -1;
	money->euro = -1;
	money->grivna = -1;
	Money& mn = *money;

	cout << "������� ����������: " << &mn << endl;
	return mn;
}

void Value_char_array(char symbol[10])
{
	cout << "�������� �� ��������\n\n";

	cout << "�������� ���������� �� :" << endl;
	cout << symbol << endl;

	for (int i = 0; i < 9; i++)
		symbol[i] = 'P';

	cout << "\n�������� ���������� �����" << endl;
	cout << symbol << endl;;
}

void Address_char_array(char(&symbol)[10])
{
	cout << "�������� �� ������\n\n";

	cout << "�������� ���������� ��: " << endl;
	cout << symbol << endl;

	for (int i = 0; i < 9; i++)
		symbol[i] = 'V';

	cout << "\n�������� ���������� ����� :" << endl;
	cout << symbol << endl;

	cout << "\n������� �� ���������� ��������" << endl;
}

void Reference_char_array(char* symbol)
{
	cout << "�������� �� ���������\n\n";

	cout << "�������� ���������� ��: " << endl;
	cout << symbol;

	for (int i = 0; i < 9; i++)
		symbol[i] = 'U';

	cout << "\n�������� ���������� ����� :" << endl;
	cout << symbol << endl;

	cout << "������� �� ���������� ��������" << endl;;
}



int main()
{
	setlocale(LC_ALL, "RU");

	int x1 = 1; int* px1 = &x1;
	char x2 = 'U'; char* px2 = &x2;
	bool x3 = false; bool* px3 = &x3;

	int array[4] = { -11,-24,-37,-48 };
	int* ar = array;

	Money money;
	money.grivna = 20547;
	money.euro = 7779;

	char symbol[10] = { '1','2', '3', '4', '5','6','7','8','9', '0' };
	int choice = 0;

	do {
		cout << "1-14 - ����� ������ �-��, 15 - �����\n";
		cout << "��� ����� --> "; cin >> choice; cout << endl;
		switch (choice)
		{
		case 1: Value_1(x1, x2, x3); break;
		case 2: Address(x1, x2, x3); break;
		case 3: Reference(px1, px2, px3); break;
		case 4: Value_2(x1, x2, x3); break;
		case 5: Value_3(x1, x2, x3); break;
		case 6: Value_array(array); break;
		case 7: Address_array(array); break;
		case 8: Reference_array(array); break;
		case 9: Value_struct(money); break;
		case 10: Address_struct(money); break;
		case 11: Reference_struct(&money);  break;
		case 12: Value_char_array(symbol); break;
		case 13: Address_char_array(symbol); break;
		case 14: Reference_char_array(symbol); break;
		}

		cout << endl;
		system("PAUSE");
		system("cls");

	} while (choice != 15);

	system("PAUSE");
}
