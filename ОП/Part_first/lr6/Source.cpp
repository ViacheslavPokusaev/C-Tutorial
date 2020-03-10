////=====// Програма роботи з різними типами структури динамічної матриці //=====//
//// Вхідні дані: 
////     цілі числа - кількість рядків N, кількість стовпців M, пункт меню
//// Вихідні дані: 
////		показ одномірної матриці, представленої у двомірну матрицю;
////		кількість елементів матриці, у яких ціла частина є непарним числом;
////		сума від’ємних елементів матриці, в яких цифра в розряді одиниць не перевищує 2;
////		сума від’ємних елементів матриці, в яких цифра в розряді одиниць не перевищує 2 для кожного рядку;
////		відсортовані рядки матриці за зростанням;
////		видалені з матриці рядки в яких 1 - ий елемент менше 2 - го.
//
//#include <iostream>
//#include <iomanip>
//#include <ctime>
//
//using namespace std;
//
///*==================================================*/
///*==========Структуры для работы программы==========*/
///*==================================================*/
//
//struct Matrix {
//	int N, M;
//	float** items; // массив указателей
//};
//
//struct Matrix1 {
//	int N, M;
//	float* items; // одномерный массив
//};
//
///*==================================================*/
///*================Меню пользователя=================*/
///*==================================================*/
//
//int Menu_user()
//{
//	// Выбранный вариант меню
//	int variant;
//	do {
//		system("cls");
//		cout << "\tМЕНЮ\n" << endl;
//		cout << "1. Создание, заполнение матриц и вывод матриц (1 и 2 Варианты)\n"
//			<< "2. Кол. элементов матриц, у которой целая часть - непарное число\n"
//			<< "3. Сумма отр. элементов, в которых цифра в роз. единиц <= 2\n"
//			<< "4. 4 пункт для всех строк --> Результат в массив --> Сортировка по возвр. на основе массива\n"
//			<< "5. Удаление с матриц строк, в которых 1-й элемент < 2-го\n"
//			<< "6. Выйти с программы\n" << endl;
//		cout << "Ваш выбор >>> ";
//		// Защита от неправильного ввода пункта меню
//		if (!(cin >> variant) || (variant < 1 || variant > 6)) {
//			system("cls");
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//		}
//	} while (variant < 1 || variant > 6);
//	return variant;
//}
//
///*==================================================*/
///*=====Вывод рандомного числа в выбр. диапазоне=====*/
///*==================================================*/
//
//// Диапазон рандома
//const double Min_Random = -22.20;
//const double Max_Random = 10.25;
//
//double random(double min, double max)
//{
//	return (double)(rand()) / RAND_MAX * (max - min) + min;
//}
//
///*==================================================*/
///*=================Создание матриц==================*/
///*==================================================*/
//
//void Create_Matrix(Matrix &object)
//{
//	bool temp = false;
//	do {
//		cout << "Введите количестов строк >>> ";
//		if (!(cin >> object.N) || (object.N < 0))
//		{
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//		}
//		else temp = true;
//	} while (temp == false);
//	temp = false;
//	do {
//		cout << "Введите количестов столбцов >>> ";
//		if (!(cin >> object.M) || (object.M < 0))
//		{
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//		}
//		else temp = true;
//	} while (temp == false);
//
//	// Создание двумерного массива (массива указателей)
//	object.items = new float*[object.N];
//	for (int i = 0; i < object.N; i++)
//		object.items[i] = new float[object.M];
//
//	// Заполнение двумерного массива
//	for (int i = 0; i < object.N; i++)
//		for (int j = 0; j < object.M; j++)
//			object.items[i][j] = random(Min_Random, Max_Random);
//}
//
//void Create_Matrix(Matrix1 &object)
//{
//	bool temp = false;
//	do {
//		cout << "Введите количестов строк >>> ";
//		if (!(cin >> object.N) || (object.N < 0))
//		{
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//		}
//		else temp = true;
//	} while (temp == false);
//	temp = false;
//	do {
//		cout << "Введите количестов столбцов >>> ";
//		if (!(cin >> object.M) || (object.M < 0))
//		{
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//		}
//		else temp = true;
//	} while (temp == false);
//
//	// Создание "двумерного массива"
//	object.items = new float[object.N * object.M];
//
//	// Заполнение "двумерного массива"
//	for (int i = 0; i < object.N * object.M; i++)
//		object.items[i] = random(Min_Random, Max_Random);
//}
//
///*==================================================*/
///*==================Вывод  матрицы==================*/
///*==================================================*/
//
//void Show_Matrix(Matrix &object)
//{
//	for (int i = 0; i < object.N; i++)
//	{
//		for (int j = 0; j < object.M; j++)
//			cout << setw(6) << setprecision(3) << object.items[i][j] << " ";
//		cout << endl;
//	}
//}
//
//void Show_Matrix(Matrix1 &object)
//{
//	for (int i = 0; i < object.N; i++)
//	{
//		for (int j = 0; j < object.M; j++)
//			cout << setw(6) << setprecision(3) << object.items[object.M * i + j] << " ";
//		cout << endl;
//	}
//}
//
///*==================================================*/
///*==========Количество непарных элементов===========*/
///*==================================================*/
//
//int Count_neparnix_elementiv(Matrix object)
//{
//	int temp; int kol = 0;
//	for (int i = 0; i < object.N; i++)
//		for (int j = 0; j < object.M; j++)
//		{
//			temp = (int)object.items[i][j];
//			if (temp % 2 != 0) kol++;
//		}
//	return kol;
//}
//
//int Count_neparnix_elementiv(Matrix1 object)
//{
//	int temp; int kol = 0;
//	for (int i = 0; i < object.N * object.M; i++)
//	{
//		temp = (int)object.items[i];
//		if (temp % 2 != 0) kol++;
//	}
//	return kol;
//}
//
///*==================================================*/
///*==========Сумма отрицательных элементов===========*/
///*==================================================*/
//
//float Sum_elementiv(Matrix object)
//{
//	float sum = 0;
//	for (int i = 0; i < object.N; i++)
//		for (int j = 0; j < object.M; j++)
//			if (object.items[i][j] < 0)
//				if ((((int)object.items[i][j])*(-1)) % 10 < 2) sum += object.items[i][j];
//	return sum;
//}
//
//float Sum_elementiv(Matrix1 object)
//{
//	float sum = 0;
//	for (int i = 0; i < object.N * object.M; i++)
//		if (object.items[i] < 0)
//			if ((((int)object.items[i])*(-1)) % 10 < 2) sum += object.items[i];
//	return sum;
//}
//
///*==================================================*/
///*==========Сумма элементов в каждой строке=========*/
///*==================================================*/
//
//void Sum_elementiv_in_each_string(Matrix &object)
//{
//	float* temp = new float[object.N];
//	int* temp1 = new int[object.N];
//	float sum = 0;
//	for (int i = 0; i < object.N; i++)
//	{
//		for (int j = 0; j < object.M; j++)
//			if (object.items[i][j] < 0)
//				if ((((int)object.items[i][j])*(-1)) % 10 < 2) sum += object.items[i][j];
//		temp[i] = sum;
//		sum = 0;
//	}
//	cout << "--->Сумма элементов в каждой строке<---\n\n";
//	for (int i = 0; i < object.N; i++)
//	{
//		cout << "Summa[" << i + 1 << "] = " << temp[i] << endl;
//	}
//	for (int i = 0; i < object.N; i++)
//		temp1[i] = i;
//	bool t = true;
//	while (t)
//	{
//		t = false;
//		for (int i = 0; i < object.N - 1; i++)
//		{
//			for (int j = 0; j < object.N - i - 1; j++)
//				if (temp[j] > temp[j + 1])
//				{
//					swap(temp[j], temp[j + 1]);
//					swap(object.items[temp1[j]], object.items[temp1[j + 1]]);
//					t = true;
//				}
//		}
//	}
//	delete temp;
//	delete temp1;
//}
//
//void Sum_elementiv_in_each_string(Matrix1 &object)
//{
//	float* temp = new float[object.N];
//	int* temp1 = new int[object.N];
//	float sum = 0; int position = 0;
//	for (int i = 0; i < object.N; i++)
//	{
//		for (int j = 0; j < object.M; j++)
//		{
//			position = object.M * i + j;
//			if (object.items[position] < 0)
//			{
//				if ((((int)object.items[position])*(-1)) % 10 < 2) sum += object.items[position];
//			}
//		}
//		temp[i] = sum;
//		sum = 0;
//	}
//	cout << "--->Сумма элементов в каждой строке<---\n\n";
//	for (int i = 0; i < object.N; i++)
//	{
//		cout << "Summa[" << i + 1 << "] = " << temp[i] << endl;
//	}
//	for (int i = 0; i < object.N; i++)
//		temp1[i] = i;
//	bool t = true;
//	while (t)
//	{
//		t = false;
//		for (int i = 0; i < object.N - 1; i++)
//		{
//			for (int j = 0; j < object.N - i - 1; j++)
//				if (temp[j] > temp[j + 1]) // сортируем по возврастанию
//				{
//					swap(temp[j], temp[j + 1]);
//					// сортировка "двумерного" массива - переставление элементов между 2 строками
//					// номера строк берутся из массива temp1
//					for (int u = 0; u < object.M; u++) // проход по столбцам матрицы
//							
//					t = true;
//				}
//		}
//	}
//	delete temp;
//	delete temp1;
//}
//
///*==================================================*/
///*==================Очистка памяти==================*/
///*==================================================*/
//
//void Clear_Ram(Matrix &object)
//{
//	for (int i = 0; i < object.N; i++)
//		delete[] object.items[i];
//	delete object.items;
//}
//
//void Clear_Ram(Matrix1 &object)
//{
//	delete object.items;
//}
//
///*==================================================*/
///*=============Удаление строк в матрице=============*/
///*==================================================*/
//
//void Clear_Matrix(Matrix1 &object)
//{
//	float* temp = new float[object.N * object.M];
//	int tempor = 0;
//	for (int i = 0; i < object.N; i++)
//	{
//		for (int j = 0; j < object.M; j++)
//		{
//			if (object.items[object.M * i + 0] > object.items[object.M * i + 1])
//			{
//				temp[tempor] = object.items[object.M * i + j];
//				tempor++;
//			}
//		}
//	}
//
//	cout << endl;
//
//	if (tempor != object.N)
//	{
//		object.N = tempor / object.M;
//		Clear_Ram(object);
//		object.items = new float[object.N * object.M];
//		for (int i = 0; i < object.N * object.M; i++)
//			object.items[i] = temp[i];
//		cout << "--->Новая матрица в результате удаления строк<---\n\n";
//		Show_Matrix(object);
//	}
//	delete temp;
//}
//
//void Clear_Matrix(Matrix &object)
//{
//	float** temp = new float*[object.N];
//	for (int i = 0; i < object.N; i++)
//		temp[i] = new float[object.M];
//	int tempor = 0;
//	for (int i = 0; i < object.N; i++)
//		if (object.items[i][0] > object.items[i][1]) {
//			temp[tempor] = object.items[i];
//			tempor++;
//		}
//
//	if (tempor != object.N)
//	{
//		int tempor1 = object.N;
//		object.N = tempor;
//		for (int i = 0; i < object.N; i++)
//			object.items[i] = temp[i];
//		cout << "\n--->Новая матрица в результате удаления строк<---\n\n";
//		Show_Matrix(object);
//		for (int i = tempor + 1; i < tempor1; i++)
//		{
//			delete[] object.items[i];
//			delete[] temp[i];
//		}
//	}
//	delete temp;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	srand((unsigned int)time(NULL));
//
//	// Установка начальных значений для матриц
//	Matrix1 m1{ 0,0, 0 }; // одномерная матрица, представленная в виде 2-х мерной
//	Matrix m{ 0, 0, 0 }; // 2-х мерная дин. матрица
//
//
//	// Вызов меню пользователя
//	int variant = Menu_user();
//	do
//	{
//		switch (variant) {
//		case 1:
//		{
//			Clear_Ram(m); Clear_Ram(m1);
//			system("cls");
//			/*cout << "СОЗДАНИЕ ОДНОМЕРНОЙ (2-х) МАТРИЦЫ\n\n";
//			Create_Matrix(m1);*/
//			cout << "\nСОЗДАНИЕ ДВУМЕРНОЙ МАТРИЦЫ\n\n";
//			Create_Matrix(m);
//			/*cout << "\n---> МАТРИЦЫ СОЗДАНЫ И ЗАПОЛНЕННЫ <---\n\n";
//			cout << "!ВЫВОД ОДНОМЕРНОЙ (2-х) МАТРИЦЫ!\n" << endl;
//			Show_Matrix(m1);*/
//			cout << "\n!ВЫВОД ДВУМЕРНОЙ МАТРИЦЫ!\n" << endl;
//			Show_Matrix(m);
//			cout << endl; system("pause");
//			variant = Menu_user();
//			break;
//		}
//		case 2:
//		{
//			system("cls");
//			/*cout << "!ВЫВОД ОДНОМЕРНОЙ (2-х) МАТРИЦЫ!\n" << endl;
//			Show_Matrix(m1);*/
//			cout << "\n!ВЫВОД ДВУМЕРНОЙ МАТРИЦЫ!\n" << endl;
//			Show_Matrix(m); cout << endl;
//			//cout << "В одномерной матрице: " << Count_neparnix_elementiv(m1) << endl;
//			cout << "В двухмерной матрице: " << Count_neparnix_elementiv(m) << endl << endl;
//			system("pause");
//			variant = Menu_user();
//			break;
//		}
//		case 3:
//		{
//			system("cls");
//			/*cout << "!ВЫВОД ОДНОМЕРНОЙ (2-х) МАТРИЦЫ!\n" << endl;
//			Show_Matrix(m1);*/
//			cout << "\n!ВЫВОД ДВУМЕРНОЙ МАТРИЦЫ!\n" << endl;
//			Show_Matrix(m); cout << endl;
//			//cout << "В одномерной матрице: " << Sum_elementiv(m1) << endl;
//			cout << "В двухмерной матрице: " << Sum_elementiv(m) << endl << endl;
//			system("pause");
//			variant = Menu_user();
//			break;
//		}
//		case 4:
//		{
//			system("cls");
//			/*cout << "--->В ОДНОМЕРНОЙ МАТРИЦЕ<---\n\nДО СОРТИРОВКИ\n\n";
//			Show_Matrix(m1);
//			cout << "\nПОСЛЕ\n\n";
//			Sum_elementiv_in_each_string(m1);
//			cout << endl; Show_Matrix(m1);*/
//			cout << "\n\n--->В ДВУМЕРНОЙ МАТРИЦЕ<---\n\n";
//			cout << "ДО СОРТИРОВКИ\n\n";
//			cout << endl; Show_Matrix(m);
//			cout << "\nПОСЛЕ\n\n";
//			Sum_elementiv_in_each_string(m);
//			cout << endl; Show_Matrix(m);
//			cout << endl; system("pause");
//			variant = Menu_user();
//			break;
//		}
//		case 5:
//		{
//			system("cls");
//			/*cout << "--->В ОДНОМЕРНОЙ МАТРИЦЕ<---\n\n";
//			Show_Matrix(m1); Clear_Matrix(m1);*/
//			cout << "\n\n--->В ДВУМЕРНОЙ МАТРИЦЕ<---\n\n";
//			Show_Matrix(m); Clear_Matrix(m);
//			cout << endl; system("pause");
//			variant = Menu_user();
//			break;
//		}
//		case 6:
//			Clear_Ram(m); Clear_Ram(m1);
//			exit(EXIT_SUCCESS);
//		}
//	} while (variant != 6);
//
//	system("pause");
//	return 0;
//}