#include<iostream>
#include <iomanip>
#include <ctime>
#include<Windows.h>
#include "IUser.h"

using namespace std;

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	IUser* user = new IUser();
	user->Menu();

	system("pause");
	return 0;
}