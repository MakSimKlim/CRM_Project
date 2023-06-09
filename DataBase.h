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
    //int i = 0;

    DataBase() // ��� ����������� � ���� ������ ������� void connectDb() �� ����������� DataBase()
    {
        //����� ������� mysql_real_connect()�������� mysql_init()��� ������������� MYSQL���������. 
        conn = mysql_init(NULL);
        bool connect = mysql_real_connect(conn, host, user, pass, nameBase, NULL, NULL, 0);
        
        //if (!connect)
        //        {
        //            fprintf(stderr, "������: ��� ���������� � ����� ������ %s\n", mysql_error(conn));
        //        }
        //        else
        //        {
        //            fprintf(stdout, "���������� � ����� MySQL �������!\n");

        //        }
    }

    void Query(string query) // ������ � ���� ������ (query - ������)
    {
        char* querChar = const_cast <char*>(query.c_str());
        mysql_set_character_set(conn, "cp1251");//��� ����������� ���������
        mysql_query(conn, querChar);

        if (res = mysql_store_result(conn))
        {
            //cout << "����������!"<<"\n";

        }
        else fprintf(stderr, "%s\n", mysql_error(conn));
    
    }
    
    //void connectDb()
    //{

    //    conn = mysql_init(NULL);
    //    bool connect = mysql_real_connect(conn, host, user, pass, nameBase, NULL, NULL, 0);
    //    if (!connect)
    //    {
    //        fprintf(stderr, "������: ��� ���������� � ����� ������ %s\n", mysql_error(conn));
    //    }
    //    else
    //    {
    //        fprintf(stdout, "���������� � ����� MySQL �������!\n");

    //    }
    //
    //}

    private:

        dbConn db; // ��������� � StructDBConn.cpp
        char* host = const_cast <char*> (db.host.c_str()); // ��������� �� host �� ������������� � char , �.�. �� �� ������������ string
        char* user = const_cast <char*> (db.nameUser.c_str());
        char* pass = const_cast <char*> (db.password.c_str());
        char* nameBase = const_cast <char*> (db.dbName.c_str());



};

