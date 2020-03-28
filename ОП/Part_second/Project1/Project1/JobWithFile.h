#pragma once
#include <vector>
#include <string>
using namespace std;

bool OpenFileForRead(ifstream& file, char* NameF);
void CloseFileForRead(ifstream& file);
bool OpenFileForWrite(ofstream& fileW, char* NameF);
void CloseFileForWrite(ofstream& fileW);
int SizeFile(ifstream& fileR);
void WriteContentInFile(ifstream& fileR, ofstream& fileW, char* NameF, char* SortTen, int j);
bool CompareUp(string x, string y);
void MainAlgoritm(ifstream& fileR, char* allTen, vector<string>& vec, char* SortT, char& Zn, int& j);
void ChangeContentFile(ifstream& fileR, ofstream& fileW, char* allTen, vector<string>& vec, char* SortT, char& Zn, int& j, char* NameF);