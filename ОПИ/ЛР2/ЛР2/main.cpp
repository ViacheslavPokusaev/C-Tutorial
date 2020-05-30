#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;

float MathExprettion1(void*);
float MathExprettion2(void*);
float MathExprettion3(void*);

float ChoseMathExprettion(int type) {

	float result = NULL, userVariable;
	float(*ptrMathExprettion[3])(void*) = { MathExprettion1, MathExprettion2, MathExprettion3 };

	cout << "Enter userVariable: "; 
	cin >> userVariable;
	void* voidPtr = &userVariable;

	try
	{
		switch (type)
		{
		case 1:
			result = ptrMathExprettion[type - 1](voidPtr);
			break;
		case 2:
			if (userVariable > 1)
			{
				result = ptrMathExprettion[type - 1](voidPtr);
			}
			else throw 1;
		case 3:
			result = ptrMathExprettion[type - 1](voidPtr);
			break;
		}
	}
	catch(exception& e)
	{
		e.what();
		cout << "Try to input other userVariable!" << endl;
	}
	catch (int a)
	{
		cout << "U should input number > than "  << 1 << endl;
	}

	return result;
}

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int numberMathExprettion;

	cout << "MathExprettions\n" << 
		"For exit enter 0!\n\n";

	do 
	{
		cout << "Enter numberMathExprettion: ";
		cin >> numberMathExprettion; //0 – вихід з програми
		cout << "Number - " << numberMathExprettion << 
			 "; Answer - " << ChoseMathExprettion(numberMathExprettion) 
			 << endl << endl;
	} 
	while (numberMathExprettion != 0);

	system("pause");
	return 0;
}

float MathExprettion1(void* ptr)
{
	float x = *static_cast<float*>(ptr);

	return
		(pow(x, 4) + 2 * pow(x, 2) - 3 * x + 1) /
		(pow(x, 2) + sqrt(3 * x) + 1) +
		2 * (pow((27 * pow(x, 3)), 1 / 6.0) - 0.5);
}

float MathExprettion2(void* ptr)
{
	float x = *static_cast<float*>(ptr);

	return
		(pow(x, 2) + 4 * x - 5 + (x - 5) * (sqrt(pow(x, 2) - 1))) /
		(pow(x, 2) - 4 * x - 5 + (x + 5) * (sqrt(pow(x, 2) - 1)));
}

float MathExprettion3(void* ptr)
{
	float x = *static_cast<float*>(ptr);

	return
		((sqrt(x) + 1) / (x * sqrt(x) + x + sqrt(x))) /
		(1 / ((pow(x, 2)) - sqrt(x)));
}