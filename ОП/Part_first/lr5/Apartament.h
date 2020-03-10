#pragma once

struct Information_about_float // Структура Адресс квартиры
{
	char Street[100];
	unsigned int Number_house;
	unsigned int Number_float;
};

struct Real_estate_float // Структура Квартира
{
	char FIO[50];
	Information_about_float Address;
	float Price;
};