#pragma once

class Matrix
{
private:
	int Rows, Columns;
	int** items;

	void CreateMatrix()
	{
		items = new int* [Rows];
		for (int i = 0; i < Rows; i++)
			items[i] = new int[Columns];
	}

public:
	Matrix(); // ctr
	~Matrix(); // des

	// Set
	void SetRows();
	void SetColumns();
	void SetItemsByUser();
	//void SetItemsByRandom(int min, int max);

	// Get
	int GetRows();
	int GetColumns();
	int** GetItems();

	// Methods
	void ShowItems();
	void ClearRam();
};