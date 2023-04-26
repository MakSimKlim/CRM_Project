#pragma once
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

class User //заготовка под родительский класс пользователей
{
public:
	//конструктор 
	User(int setId, int setPosition, string setLastName, string setFirstName, string setPatronymic)
	{
		this->id;
		this->position;


		this->lastname;    // фамилия
		this->firstname;   // имя
		this->patronymic;  // отчество
	}

	User() {}

	//методы класса User:

	////получить данные о пользователе
	//void getUser(int getId)
	//{
	//
	//}


private:
	int id{};
	int position{};       // должность

	string lastname;      //фамилия
	string firstname;     // имя
	string patronymic;    // отчество
};


