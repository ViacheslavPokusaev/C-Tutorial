#include <windows.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

bool CompareUp(string x, string y) // ��������� �� ������������ ����� � ������������
{
	if (x.length() < y.length()) return true;
	else return false;
}

int main()
{
	setlocale(LC_ALL, "rus");

	int nfilesize;			   // ������ �����
	bool check = true;		   // �������� �� ����. ������
	char* allTensesInDocument; // ��� ����������� � ���������
	char* SortTenses;		   // ��������������� �����������
	int j;					   // ������� ��� ��������������� ������������
	char Znak;				   // ����� �������� ������������� �����������
	vector<string> storage;	   // ������ ��� �������� ���� � 1 ������������
	char* NameFile = new char[200];	   // ��������������� ����� .txt
	bool exit = true;		   // ����� �� ���������
	ifstream fileRead;		   // ���� ��� ������	
	ofstream fileWrite;        // ���� ��� ������(NameFile);

	while (exit != false)
	{
		j = 0;
		system("cls");
		cout << "For exit from program write 'stop' or 'exit' or '0'" << endl << endl;
		cout << "Enter path to file (write with 2*\): ";
		cin >> NameFile;

		fileRead.open(NameFile);	
		if (!fileRead.is_open()) // �������� ������� ����� � ������
		{
			cout << "ERROR: not file - " << NameFile << ";\n" << "Check input data!!!" << endl;
			check = false;
			system("PAUSE");
		}
		else { cout << "File is openning!\n"; check = true; }

		if (check) // �������� �� ����������� ��������� ������
		{
			// ��������� ������ �����
			fileRead.seekg(0, ios::end);  //
			nfilesize = fileRead.tellg(); //
			fileRead.seekg(0, ios::beg);  //
			//

			allTensesInDocument = new char[nfilesize];
			SortTenses = new char[nfilesize];

			while (!fileRead.eof()) // ������ ���� �� �����
			{
				fileRead.getline(allTensesInDocument, 100, ' '); // ������ ������ �����
				storage.push_back(string(allTensesInDocument));  // ���������� ��� � ������
				Znak = allTensesInDocument[strlen(allTensesInDocument) - 1]; // ���������� ���� � ����� ������� �����

				if (Znak == '.' || Znak == '?' || Znak == '!') // ���� ����������� ���������
				{
					allTensesInDocument[strlen(allTensesInDocument) - 1] = '\0'; // ������� �������� ����
					storage.pop_back(); // ������� ����� � ������ � �����
					storage.push_back(string(allTensesInDocument)); // ���������� ����� ��� �����

					sort(storage.begin(), storage.end(), CompareUp); // ��������� �� ������������ � ������� ��������� ���������� � �������

					unsigned int vector_size = storage.size(); // ��������� ��������� ���� � �������
					for (int i = 0; i < vector_size; i++) // �������� ������ �����
					{
						for (int i1 = 0; i1 < storage[i].length(); i1++, j++) // ��������� ������ ������ � �����
						{
							SortTenses[j] = storage[i][i1]; // ���������� ��� � ������
						}
						SortTenses[j] = ' '; j++;
					}
					SortTenses[j - 1] = Znak; SortTenses[j] = ' '; j++; // �� �������� ��� ����� � ����� ����������� � �������
					storage.clear();
				}
			}
			storage.clear(); // ������� ������
			fileRead.close();

			fileWrite.open(NameFile);  // � ��������� ��� ������
			for (int i = 0; i < j; i++) // ���������� �� ����� �������� �������� � ����� SortTenses
				fileWrite << SortTenses[i];
			fileWrite << endl;
			fileWrite.close();

			cout << "Job is done! Do you want to continue? (1(true) - YES, 0(fasle) - NO)\nYour choise >>> "; cin >> exit;
			system("cls");
		}
	}
	return 0;
}