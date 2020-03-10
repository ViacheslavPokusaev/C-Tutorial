#pragma once
#include "Apartament.h"

Real_estate_float Set_dannie(Real_estate_float object); // Добавление новых квартир
void Get_dannie(Real_estate_float object[], int Current_position); // Вывод списка всех квартир
void Search_float_for_price(Real_estate_float object[], float price, int current_position); // Поиск квартиры по цене
void Minimum_price_on_float(Real_estate_float object[], int current_position); // Вывод списка квартир, которые имеют минимальную цену
void Information_about_name_float(Real_estate_float object[], int current_position); // Поиск конкретной квартиры
void Sort_struct(Real_estate_float object[], int vibor, int current_position); // Сортировка квартир по возрастании или спаданию
