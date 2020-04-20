#pragma once
#include<fstream>
#include "Float.h"
using namespace std;

void AddToFile(ofstream &out, Real_estate_float &_float, int &countStructInFile);
void ReadAllFromFile(ifstream& in, int countStructInFile);
void ShowFloatWithDefinitelyPrice(ifstream& in, int countStructInFile);
void ShowLowFloats(ifstream& in, int countStructInFile);
void CheckFile(ofstream& out, char* NameFile);