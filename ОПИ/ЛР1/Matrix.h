#pragma once

struct Matrix
{
	int** array = nullptr;
	int rows = -1, columns = -1; // �������-������

	void Create_array(); // �������� �������
	void Random_Fill(); // ���������� ������� ���������� �������
	void User_Fill(); // ���������� ������� �������������
	void Show_array(); // �������� �������
	void Delete(); // �������� �������
};