#pragma once
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

class User //��������� ��� ������������ ����� �������������
{
public:
	//����������� 
	User(int setId, int setPosition, string setLastName, string setFirstName, string setPatronymic)
	{
		this->id;
		this->position;


		this->lastname;    // �������
		this->firstname;   // ���
		this->patronymic;  // ��������
	}

	User() {}

	//������ ������ User:

	////�������� ������ � ������������
	//void getUser(int getId)
	//{
	//
	//}


private:
	int id{};
	int position{};       // ���������

	string lastname;      //�������
	string firstname;     // ���
	string patronymic;    // ��������
};


