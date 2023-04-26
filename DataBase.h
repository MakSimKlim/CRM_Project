#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <mysql.h>
#include "StructDBConn.cpp"

using namespace std;

class DataBase
{
public:
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;

    DataBase() // заменим void connectDb() на конструктор DataBase()
    {
        conn = mysql_init(NULL);
        bool connect = mysql_real_connect(conn, host, user, pass, nameBase, NULL, NULL, 0);
        mysql_set_character_set(conn, "cp1251");//для отображения Кириллицы
        if (!connect)
                {
                    fprintf(stderr, "Ошибка: Нет соединения с базой данных %s\n", mysql_error(conn));
                }
                else
                {
                    fprintf(stdout, "Соединение с базой MySQL успешно!\n");

                }
    }
    
    //void connectDb()
    //{

    //    conn = mysql_init(NULL);
    //    bool connect = mysql_real_connect(conn, host, user, pass, nameBase, NULL, NULL, 0);
    //    if (!connect)
    //    {
    //        fprintf(stderr, "Ошибка: Нет соединения с базой данных %s\n", mysql_error(conn));
    //    }
    //    else
    //    {
    //        fprintf(stdout, "Соединение с базой MySQL успешно!\n");

    //    }
    //
    //}

    private:

        dbConn db;
        char* host = const_cast <char*> (db.host.c_str()); // указатель на host но пререведенный в char , т.к. он не воспринимает string
        char* user = const_cast <char*> (db.nameUser.c_str());
        char* pass = const_cast <char*> (db.password.c_str());
        char* nameBase = const_cast <char*> (db.dbName.c_str());



};

