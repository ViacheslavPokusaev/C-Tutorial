#include<iostream>
#include<fstream>

using namespace std;

struct Data {
	char name[20];
	int age;
	float weight;
};

int main()
{
	Data horde[7] = { {"Barsik", 3, 3.2}, {"Murzik", 7, 8.7}, {"Pushok", 5, 6.1}, {"Masyanya", 10, 12.5}, 
						{"Chera", 1, 1.5}, {"Pyzhyk", 2, 3}, {"Chizhyk", 2, 2.8} };

	//write array to file
	ofstream out; 
	out.open("test.dat", ios::binary | ios::out | ios::trunc);
	out.write(static_cast <char*>(static_cast <void*> (horde)), sizeof horde);
	out.close();

	//read from file first, fourth and seventh records
	ifstream in;
	Data pet;
	int sizeOfRecord = sizeof pet;
	in.open("test.dat", ios::binary | ios::in);
	in.read(static_cast <char*>(static_cast <void*> (&pet)), sizeOfRecord);	//read first record, set to second record
	cout << '(' << pet.name << ", age " << pet.age << ", weight " << pet.weight << ")\n";
	in.seekg(2 * sizeOfRecord, ios::cur);	//set to fourth record
	in.read(static_cast <char*>(static_cast <void*> (&pet)), sizeOfRecord);	//read fourth record, set to fifth record
	cout << '(' << pet.name << ", age " << pet.age << ", weight " << pet.weight << ")\n";
	in.seekg(-sizeOfRecord, ios::end);	//set to seventh record
	in.read(static_cast <char*>(static_cast <void*> (&pet)), sizeOfRecord);	//read seventh record, set to eof
	cout << '(' << pet.name << ", age " << pet.age << ", weight " << pet.weight << ")\n";
	in.close();

	//"Murzik" <-> "Pyzhyk"
	Data murzik, ryzhyk;
	long posMurzik, posRyzhyk;
	fstream inout("test.dat", ios::binary | ios::in | ios::out);
	//read Murzik
	inout.seekg(sizeOfRecord, ios::beg);	//set to Murzik record to read
	posMurzik = inout.tellg();	//save position of Murzik
	inout.read(static_cast <char*>(static_cast <void*> (&murzik)), sizeOfRecord);	//read Murzik record, set to Pushok record
	//read Pyzhyk
	inout.seekg(3 * sizeOfRecord, ios::cur);	//set to Pyzhyk record to read
	posRyzhyk = inout.tellg();	//save position of Pyzhyk
	inout.read(static_cast <char*>(static_cast <void*> (&ryzhyk)), sizeOfRecord);	//read posRyzhyk record, set to Chizhyk record
	//write Murzik to position of Pyzhyk
	inout.seekp(posRyzhyk, ios::beg);
	inout.write(static_cast <char*>(static_cast <void*> (&murzik)), sizeOfRecord);
	//write Pyzhyk to position of Murzik
	inout.seekp(posMurzik, ios::beg);
	inout.write(static_cast <char*>(static_cast <void*> (&ryzhyk)), sizeOfRecord);
	inout.close();

	//horde information print
	in.open("test.dat", ios::binary); //default ios::in
	cout << "\nhorde information:\n\n";
	in.read(static_cast <char*>(static_cast <void*> (&pet)), sizeOfRecord);	//read seventh record, set to eof
	while(!in.eof())
	{
		cout << '(' << pet.name << ", age " << pet.age << ", weight " << pet.weight << ")\n";
		in.read(static_cast <char*>(static_cast <void*> (&pet)), sizeOfRecord);	//read seventh record, set to eof
	}
	in.close();

	return 0;
}