#pragma once

struct Matrix
{
	int** array = nullptr;
	int rows = -1, columns = -1; // Столбцы-строки

	void Create_array(); // Создание матрицы
	void Random_Fill(); // Заполнение матрицы рандомными числами
	void User_Fill(); // Заполнение матрицы пользователем
	void Show_array(); // Показать матрицу
	void Delete(); // Удаление матрицы
};