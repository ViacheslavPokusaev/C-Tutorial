///*9)   ���� ���������� ����� n > 1. ������ �������:
//�0 = �1 = 1; � = � - 2 + (�1 - 1) / (2 ^ (� - 1)); � = 2, 3, ...
//������ �0 * �1 * ... * �n
//*/
//
//#include <iostream>
//#include <Windows.h>
//#include <math.h>
//
//using namespace std;
//
//int main()
//{
//	setlocale(LC_CTYPE, "rus");
//
//	// ���������� ������ ��� ��������� �������:
//	//current_a - �������� ���� ����, n - ������� ������ � ���; 
//	//mul - ��������� �������� ��� ������ ���� �� �����;
//	//temp1, temp2 - �����, �� ������� ��� ��������� ����������������� �� ������������ ������� ������.
//	float temp1, temp2, current_a, mul; int n;
//	//��������� temp1 � temp2 �������� ������� � ������� ������� ������ ��������� ���� ��������
//	temp1 = temp2 = mul = 1;
//	cout << "����-���� ���� ���� = �i - 2 + (�1 - 1) / (2 ^ (i - 1))" << endl;
//	cout << "������� = �0 * �1 * ... * �i" << endl << endl;
//	cout << "������ ������� ������ ��������� ���� (n >= 2): ";  cin >> n;
//	for (; n < 2; ) //�������� �� ����������� �������� �����
//	{
//		cout << "ʳ������ ������ ��������� ���� ������� ���� �� ����� 2. �������� ������!" << endl;
//		cout << "������ ������� ������ ��������� ���� (n >= 2): "; cin >> n;
//	}
//
//	//�� ��������� ����� ���������� �������, ��������� � 3-�� ��������, ������ 1 � 2 = 1
//	for (int i = 2; i <= n; i++)
//	{
//		current_a = temp1 + (temp2) / pow(2, i - 1); //�� �������� ��������� �������� ���� ����
//		//������ �������������� �� ��������� �������� ��������� ���� �� ��������� �� �������� ��������
//		temp1 = temp2;
//		temp2 = current_a;
//		//
//		mul *= current_a; //���������� ������� ��������� ����
//	}
//	cout << "������� ��������� ���� = " << mul << endl; //���� ���������� ��������
//	system("PAUSE");  // �������� ��� ��������� ����������
//	return 0;  // ����� � ������� main()
//}
