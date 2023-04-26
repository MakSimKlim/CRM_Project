#pragma once
#include <iostream>

using namespace std;

// наипримейший доступ к базе данных, но скрытый от всех в отдельный файл, который потом спр€чем в недрах программы
struct dbConn
{
	string host{"localhost"};
	string nameUser{ "root" };
	string password{""};
	string dbName{ "crmbase" };

};