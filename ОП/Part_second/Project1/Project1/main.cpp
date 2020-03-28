#include <windows.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

bool CompareUp(string x, string y) // сортируем по возврастанию слова в предоложению
{
	if (x.length() < y.length()) return true;
	else return false;
}

int main()
{
	setlocale(LC_ALL, "rus");

	int nfilesize;			   // размер файла
	bool check = true;		   // проверка на корр. данных
	char* allTensesInDocument; // все предложения в документе
	char* SortTenses;		   // отсортированные предложения
	int j;					   // счётчик для отсортированных предоложений
	char Znak;				   // каким символом заканчивается предложение
	vector<string> storage;	   // вектор для хранение слов в 1 предоложении
	char* NameFile = new char[200];	   // местонахождение файла .txt
	bool exit = true;		   // выход из программы
	ifstream fileRead;		   // файл для чтения	
	ofstream fileWrite;        // файл для записи(NameFile);

	while (exit != false)
	{
		j = 0;
		system("cls");
		cout << "For exit from program write 'stop' or 'exit' or '0'" << endl << endl;
		cout << "Enter path to file (write with 2*\): ";
		cin >> NameFile;

		fileRead.open(NameFile);	
		if (!fileRead.is_open()) // проверка наличия файла с тестом
		{
			cout << "ERROR: not file - " << NameFile << ";\n" << "Check input data!!!" << endl;
			check = false;
			system("PAUSE");
		}
		else { cout << "File is openning!\n"; check = true; }

		if (check) // проверка на правилность вказанных данных
		{
			// Считываем размер файла
			fileRead.seekg(0, ios::end);  //
			nfilesize = fileRead.tellg(); //
			fileRead.seekg(0, ios::beg);  //
			//

			allTensesInDocument = new char[nfilesize];
			SortTenses = new char[nfilesize];

			while (!fileRead.eof()) // Читаем файл до конца
			{
				fileRead.getline(allTensesInDocument, 100, ' '); // читаем каждое слово
				storage.push_back(string(allTensesInDocument));  // записываем его в вектор
				Znak = allTensesInDocument[strlen(allTensesInDocument) - 1]; // запоминаем знак в конце каждого слова

				if (Znak == '.' || Znak == '?' || Znak == '!') // если предложение закончено
				{
					allTensesInDocument[strlen(allTensesInDocument) - 1] = '\0'; // убираем конечный знак
					storage.pop_back(); // удаляем слово с знаком в конце
					storage.push_back(string(allTensesInDocument)); // записываем слово без знака

					sort(storage.begin(), storage.end(), CompareUp); // сортируем по возврастанию с помощью алгоритма сотрировки и вектора

					unsigned int vector_size = storage.size(); // считываем количесто слов в векторе
					for (int i = 0; i < vector_size; i++) // получаем каждое слово
					{
						for (int i1 = 0; i1 < storage[i].length(); i1++, j++) // считываем каждый символ в слове
						{
							SortTenses[j] = storage[i][i1]; // записываем его в массив
						}
						SortTenses[j] = ' '; j++;
					}
					SortTenses[j - 1] = Znak; SortTenses[j] = ' '; j++; // не забываем про знаки в конце предложения и пробелы
					storage.clear();
				}
			}
			storage.clear(); // очищаем память
			fileRead.close();

			fileWrite.open(NameFile);  // и открываем для записи
			for (int i = 0; i < j; i++) // записываем всё кроме ненужных символов в конце SortTenses
				fileWrite << SortTenses[i];
			fileWrite << endl;
			fileWrite.close();

			cout << "Job is done! Do you want to continue? (1(true) - YES, 0(fasle) - NO)\nYour choise >>> "; cin >> exit;
			system("cls");
		}
	}
	return 0;
}