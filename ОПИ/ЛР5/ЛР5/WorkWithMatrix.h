#pragma once
#include "Matrix.h"
#include "InputOutput.h"
#include <string>

using namespace std;

void Main_algorithm(Matrix matrix);
void Change_array(Matrix matrix, int current_column);
void Change_polidrom(Matrix matrix, int current_column, float avr);
void Change_other_array(Matrix matrix, int current_column, string str);