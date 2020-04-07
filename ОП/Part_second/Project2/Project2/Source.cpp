#include <fstream>
#include <iostream>
#include "Apart.h"
#include "Functional.h"
#pragma warning(disable : 4996)

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int const const_size = 2;
    int temp = 0;
    const char* FName = "C:\\Users\\User\\Desktop\\2.txt";
    ifstream in(FName, ios::binary);
    ofstream f(FName, ios::binary | ios::app);

    Real_estate_float fl[const_size];

    Set_dannie(f);
    temp++;

    Set_dannie(f);
    temp++;

    f.close();

    Get_data(fl, temp, in);
    cin.get();
}