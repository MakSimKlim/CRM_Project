#pragma once
#include <iostream>

using namespace std;

// ������������ ������ � ���� ������, �� ������� �� ���� � ��������� ����, ������� ����� ������� � ������ ���������
struct dbConn
{
	string host{"localhost"};
	string nameUser{ "root" };
	string password{""};
	string dbName{ "crmbase" };

};