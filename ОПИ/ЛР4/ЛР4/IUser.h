#pragma once
#include "Matrix.h"
#include "MatrixAlgorithms.h"

class IUser
{
private:
	Matrix* matrix;
	MatrixAlgorithms* matrixAlgorithms;

public:
	IUser();
	~IUser();

	void Menu();
};

