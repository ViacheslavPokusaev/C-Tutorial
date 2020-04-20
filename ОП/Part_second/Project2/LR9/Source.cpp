#include<iostream>
#include<fstream>
#include "Float.h"

using namespace std;

int main()
{
	Real_estate_float floats[3] = {
		{ "Pokusaev Vyacheslav Oleksiyovich", "c. Dnipro, d. Topol - 1", 6, 44, 30000 },
		{ "Kostychdenko Mark Oleg", "c. Dnipro, d. Petrovskiy", 56, 1, 10000},
		{ "Guzenko Artem Artemovich", "c. Dnipro, d. Leftbeach - 3", 77, 777, 12500 }
	};
	
	ofstream out;
	out.open("test.dat", ios::binary | ios::out | ios::trunc);
	out.write(static_cast <char*>(static_cast <void*> (floats)), sizeof floats);
	out.close();

	ifstream in;
	Real_estate_float _real_estate_float;
	int sizeOfRecord = sizeof _real_estate_float;
	in.open("test.dat", ios::binary | ios::in);
	while (in.eof() != true)
	{
		in.read(static_cast <char*>(static_cast <void*> (&_real_estate_float)), sizeOfRecord);	//read first record, set to second record
		cout << '(' << _real_estate_float.FIO << ", Price " << _real_estate_float.Price << 
			", Address:\nAddress(number float) " << _real_estate_float.Address.Number_float <<
			",\nAddress(number house) " << _real_estate_float.Address.Number_house <<
			",\nAddress(number street) " << _real_estate_float.Address.Street <<
			")\n";
	}
	in.close();

	system("pause");
	return 0;
}