#include<iostream>
#include<fstream>
#include "Float.h"
#include "JobWithFile.h"

using namespace std;

// Add struct to file
void AddToFile(ofstream& out, Real_estate_float& _float, int& countStructInFile)
{	
	out.write(static_cast <char*>(static_cast <void*> (&_float)), sizeof _float);
	countStructInFile++;
}
// Read all records from file
void ReadAllFromFile(ifstream& in, int countStructInFile)
{
	Real_estate_float _real_estate_float;
	int sizeOfRecord = sizeof _real_estate_float;

	int currentPosition = 0;
	while (countStructInFile != currentPosition)
	{
		in.read(static_cast <char*>(static_cast <void*> (&_real_estate_float)), sizeOfRecord);
		cout << '(' << _real_estate_float.FIO << ", Price " << _real_estate_float.Price <<
			", Address:\nAddress(number float) " << _real_estate_float.Address.Number_float <<
			",\nAddress(number house) " << _real_estate_float.Address.Number_house <<
			",\nAddress(number street) " << _real_estate_float.Address.Street <<
			")\n";
		currentPosition++;
	}
	in.clear();
	in.seekg(0, ios_base::beg);
	cout << endl;
}
// Output floats with user input price
void ShowFloatWithDefinitelyPrice(ifstream& in, int countStructInFile)
{
	Real_estate_float _real_estate_float;
	int Price, currentPosition = 0, sizeOfRecord = sizeof _real_estate_float;
	cout << "Enter price: "; cin >> Price;

	while (countStructInFile != currentPosition)
	{
		in.read(static_cast <char*>(static_cast <void*> (&_real_estate_float)), sizeOfRecord);
		if (_real_estate_float.Price == Price)
			cout << '(' << _real_estate_float.FIO <<
			", Address:\nAddress(number float) " << _real_estate_float.Address.Number_float <<
			",\nAddress(number house) " << _real_estate_float.Address.Number_house <<
			",\nAddress(number street) " << _real_estate_float.Address.Street <<
			")\n";
		currentPosition++;
	}
	in.clear();
	in.seekg(0, ios_base::beg);
	cout << endl;
}
// The lowest cost float
void ShowLowFloats(ifstream& in, int countStructInFile)
{
	Real_estate_float _real_estate_float;
	Real_estate_float temp;
	int sizeOfRecord = sizeof _real_estate_float, currentPosition = 0;
	in.read(static_cast <char*>(static_cast <void*> (&_real_estate_float)), sizeOfRecord);

	while (countStructInFile != currentPosition)
	{
		in.read(static_cast <char*>(static_cast <void*> (&temp)), sizeOfRecord);
		if (_real_estate_float.Price > temp.Price) _real_estate_float = temp;
		currentPosition++;
	}

	cout << '(' << _real_estate_float.FIO <<
		", Address:\nAddress(number float) " << _real_estate_float.Address.Number_float <<
		",\nAddress(number house) " << _real_estate_float.Address.Number_house <<
		",\nAddress(number street) " << _real_estate_float.Address.Street <<
		")\n";

	in.clear();
	in.seekg(0, ios_base::beg);
	cout << endl;
}
// Check file
void CheckFile(ofstream& out, char* NameFile)
{
	out.open(NameFile, ios::binary | ios::app);
	if (!out.is_open())
	{
		out.open(NameFile, ios::binary | ios::out | ios::trunc);
		cout << "File is created!" << endl;
	}
	else { cout << "File is openning!\n"; }
}