#pragma once
#include <iostream>
#include "Matrix.h"
using namespace std;

class MatrixAlgorithms
{
private:
	int* Indexs;
	int Length;

public:
	MatrixAlgorithms();
	~MatrixAlgorithms();

	void SetIndexs(int Size);

	// TypeCoincidence % 2 == 0 - Vertical
	// TypeCoincidence % 2 != 0 - Gorizontal
	void SearchCoincidences(int TypeCoincidence, Matrix* matrix);
	void ShowCoincidences(int Item, int RowOrColumn, int TypeCoincidence);
	void ClearRam();
};

