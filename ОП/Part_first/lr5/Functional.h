#pragma once
#include "Apartament.h"

Real_estate_float Set_dannie(Real_estate_float object); // ���������� ����� �������
void Get_dannie(Real_estate_float object[], int Current_position); // ����� ������ ���� �������
void Search_float_for_price(Real_estate_float object[], float price, int current_position); // ����� �������� �� ����
void Minimum_price_on_float(Real_estate_float object[], int current_position); // ����� ������ �������, ������� ����� ����������� ����
void Information_about_name_float(Real_estate_float object[], int current_position); // ����� ���������� ��������
void Sort_struct(Real_estate_float object[], int vibor, int current_position); // ���������� ������� �� ����������� ��� ��������
