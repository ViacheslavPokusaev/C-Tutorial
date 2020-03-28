#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "JobWithFile.h"

using namespace std;

///////////////////
// ЗАКРЫВАЕМ ФАЙЛ//
///////////////////
void CloseFileForRead(ifstream& file)
{
	file.close();
}
///////////////////
// ОТКРЫВАЕМ ФАЙЛ//
///////////////////
bool OpenFileForWrite(ofstream& fileW, char* NameF)
{
	cout << "Enter path to file: ";
	cin >> NameF;

	fileW.open(NameF);
	if (!(fileW.is_open())) // проверка наличия файла с тестом
	{
		cout << "ERROR: not file - " << NameF << ";";
		system("PAUSE");
		return true;
	}
	else
	{
		cout << "File is openning!";
		system("PAUSE");
		return false;
	}
}

///////////////////
// ЗАКРЫВАЕМ ФАЙЛ//
///////////////////
void CloseFileForWrite(ofstream& fileW)
{
	fileW.close();
}

/////////////////////////
// УЗНАЁМ РАЗМЕР ФАЙЛА //
/////////////////////////
int SizeFile(ifstream& fileR)
{
	fileR.seekg(0, ios::end);
	int nfilesize = fileR.tellg();
	fileR.seekg(0, ios::beg);
	return nfilesize;
}

///////////////////////
// ЗАПИСЫВАЕМ В ФАЙЛ //
///////////////////////
void WriteContentInFile(ifstream& fileR, ofstream& fileW, char* NameF, char* SortTen, int j)
{
	CloseFileForRead(fileR);
	if (OpenFileForWrite(fileW, NameF))
	{
		for (int i = 0; i < j; i++) // записываем всё кроме ненужных символов в конце SortTenses
			fileW << SortTen[i];
		fileW << endl;
	}
	CloseFileForWrite(fileW);
}

////////////////////////////////
// СОРТИРОВКА СЛОВ В          //
// ПРЕДЛОЖЕНИИ ПО ВОЗРАСТАНИЮ //
////////////////////////////////
bool CompareUp(string x, string y) // сортируем по возврастанию слова в предоложению
{
	if (x.length() < y.length()) return true;
	else return false;
}

/////////////////////////
// АЛГОРИТМ СОРТИРОВКИ //
// СЛОВ В ПРЕДЛОЖЕНИИ  //
/////////////////////////
void MainAlgoritm(ifstream& fileR, char* allTen, vector<string>& vec, char* SortT, char& Zn, int& j)
{
	while (!fileR.eof()) // Читаем файл до конца
	{
		fileR.getline(allTen, 100, ' ');
		vec.push_back(string(allTen));
		Zn = allTen[strlen(allTen) - 1];

		if (Zn == '.' || Zn == '?' || Zn == '!')
		{
			allTen[strlen(allTen) - 1] = '\0';
			vec.pop_back();
			vec.push_back(string(allTen));

			sort(vec.begin(), vec.end(), CompareUp);

			unsigned int vector_size = vec.size();
			for (int i = 0; i < vector_size; i++)
			{
				for (int i1 = 0; i1 < vec[i].length(); i1++, j++)
				{
					SortT[j] = vec[i][i1];
				}
				SortT[j] = ' '; j++;
			}
			SortT[j - 1] = Zn; SortT[j] = ' '; j++;
			vec.clear();
		}
	}
	vec.clear();
}

///////////////////////////////
// ИЗМЕНЯЕМ СОДЕРЖИВОЕ ФАЙЛА //
///////////////////////////////
void ChangeContentFile(ifstream& fileR, ofstream& fileW, char* allTen, vector<string>& vec, char* SortT, char& Zn, int& j, char* NameF)
{
	int nfilesize = SizeFile(fileR);
	allTen = new char[nfilesize];
	SortT = new char[nfilesize];

	MainAlgoritm(fileR, allTen, vec, SortT, Zn, j);

	WriteContentInFile(fileR, fileW, NameF, SortT, j);
}