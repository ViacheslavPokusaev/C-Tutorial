// Получить матрицу В; Условие внизу
// Входные данные: numberI, numberJ - целые числа; A[i, j] - матрица, состоящая из действительных чисел
// Выходные данные: В - матрица, елемент которой b[i,j] равняется минимальному элементу 
// среди элементов подматрицы А' порядка i х j, которая распаложена в верхнем левом углу матрицы А;
#include <iostream>
#include <iomanip>
#include <time.h>
#include <ctime>

using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	srand((unsigned int)time(NULL));
	// Замеры роботы программы
	time_t start, end;
	time(&start);

	int numberI, numberJ, i, j;
	float min;

	numberJ = numberI = 10000;

	float** A = new float*[10000];

	for (int i = 0; i < 10000; i++)
		A[i] = new float[10000];

	float** B = new float*[10000];

	for (int i = 0; i < 10000; i++)
		B[i] = new float[10000];

	for (i = 0; i < numberI; i++) // Заполнение матрицы А
	{
		for (j = 0; j < numberJ; j++)
			A[i][j] = (rand() % 10000);
	}

	min = A[0][0];

	//for (i = 0; i < numberI; i++) // Вывод матрицы А
	//{
	//	for (j = 0; j < numberJ; j++)
	//		cout << A[i][j] << "  ";
	//	cout << endl;
	//}

	for (i = 0; i < numberI; i++) // Вычисление чисел матрицы В
	{
		for (j = 0; j < numberJ; j++)
		{
			// Поиск минимального элемента среди чисел подматрицы А, диапазон поиска - i, j текущего элемента B
			for (int i1 = 0; i1 <= i; i1++)
			{
				for (int j1 = 0; j1 <= j; j1++)
				{
					if (min > A[i1][j1]) // Проверка на минимум
					{
						min = A[i1][j1]; // Минимум найден! Переменная min переприсвоена новым минимумом
					}
				}
			}
			// Присвоение текущему В[i,j] минимального элемента среди элементов подматрицы А' 
			// порядка i х j, которая находиться в верхнам левом углу матрицы А.
			B[i][j] = min;
		}
	}

	//for (i = 0; i < numberI; i++) // Вывод матрицы В
	//{
	//	for (j = 0; j < numberJ; j++)
	//		cout << B[i][j] << "   ";
	//	cout << endl;
	//}

	time(&end);
	double seconds = difftime(end, start);
	printf("\nThe time: %f seconds\n", seconds);

	system("PAUSE");
	return 0;
}
