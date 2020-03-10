//----------// Програма створення та управління списком квартир //----------//
// Вхідні дані: 
// - масиви символів - ПІБ власника квартири FIO та адреса квартири Street, 
// - цілі числа - номер будинку Street, номер квартири Number_float, вибір пункту меню vibor,
// - дійсне число - ціна квартири Price
// Вихідні дані: 
// - список усіх квартир
// - список квартир вказаної ціни
// - список квартир з мінімальною ціною
// - інформація про вказану квартиру у списку
// - відсортований список квартир

#include <iostream>
#include <iomanip>
#include "Apartament.h"
#include "Functional.h"
#define Size_struct 5 // Размер массива
using namespace std;

int Menu_user() // Мeню пользователя
{
	// Выбранный вариант меню
	int variant;
	do {
		system("cls");
		cout << "\tМЕНЮ\n" << endl;
		cout << "1. Добавить квартиру\n"
			<< "2. Вывести весь список квартир\n"
			<< "3. Вывести список квартир за указанной ценой\n"
			<< "4. Квартиры с минимальными ценами\n"
			<< "5. Поиск квартиры за указанным адрессом\n"
			<< "6. Сортировка квартир за ценами\n"
			<< "7. Выйти с программы\n" << endl;
		cout << "Ваш выбор >>> ";
		// Защита от неправильного ввода пункта меню
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

	Real_estate_float fl[Size_struct] // Создание структуры Квартира на 5 элементов
	{
		{ "Покусаев Вячеслав Алексеевич", "c. Dnipro, d. Topol - 1", 6, 44, 30000 },
		{ "Костюченко Марк Денисович", "c. Dnipro, d. Petrovskiy", 56, 1, 10000},
		{ "Гузенко Артём Борисович", "c. Dnipro, d. Leftbeach - 3", 77, 777, 12500 }
	};

	int variant = Menu_user();

	do
	{
		switch (variant) {
		case 1:
		{
			system("cls");
			cout << "---> ДОБАВЛЕНИЕ НОВОЙ КВАРТИРЫ <---\n\n";
			if (Current_position_index_struct <= 5) // Проверка на размер массива
			{
				fl[Current_position_index_struct] = Set_dannie(fl[Current_position_index_struct]);
				Current_position_index_struct++;
				cout << "---> КВАРТИРА ДОБАВЛЕНА <---\n";
			}
			else cout << "!Структура заполненна! Добавление новых квартир запрещенно!" << endl;
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
				cout << "---> ПОИСК КВАРТИРЫ ЗА ЦЕНОЙ <---\n\n" << "Введите цену >>> ";
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
				cout << "---> СОРТИРОВКА <---\n\n" << "1 - Сортировать квартиры по возврастанию\n" << "2 - Сортировать квартиры по спаданию\n" << "Ваш выбор >>> ";
				if (!(cin >> temp) || (temp < 1 || temp > 2)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			} while (temp < 1 || temp > 2);
			Sort_struct(fl, temp, Current_position_index_struct);
			cout << "\nКвартиры отсортированы!" << endl;
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