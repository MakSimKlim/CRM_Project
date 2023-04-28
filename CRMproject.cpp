// CRM.cpp 
//
// crm - система упраления 
// 
// Например для образовательного CRM могут быть классы: 
//1) user (препод, студент, администратор)
//2) Предметы
//3) Задачи
//
// Создание базы данных: 
//1).SQL - запрос на создание структуры в phpMyAdmin:
//CREATE TABLE `users` (
//`idUser` int(11) unsigned NOT null AUTO_INCREMENT, #not null - значение полей не может быть пустым, AUTO_INCREMENT - автоматическое заполнение порядковым номером
//`lastName` varchar(256) not null,
//`firstName` varchar(256) not null,
//`patronymic` varchar(256) null,                    #null - значение полей может быть пустым
//`position` int(11) not null,
//PRIMARY KEY(`idUser`)                              # первичный ключ, объявляется всегда
//);

#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <mysql.h>
#include "Header.h"
#include "DataBase.h"
#include <string>
//#include <mysqlx/xdevapi.h>


using namespace std;
int main()

{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    DataBase db;    // инициализация объекта db класса DataBase, применяется без db.connectDb(), если вместо void connect используется конструктор
    //db.connectDb(); // обращение объекта к методу класса DataBase, когда используется void connect

    string name{};
    string lastName{};
    string patronymic{};
    int position{};

    cout << "Введите фамилию:" << "\n";
    cin >> name;
    cout << "Введите имя:" << "\n";
    cin >> lastName;
    cout << "Введите отчество:" << "\n";
    cin >> patronymic;
    cout << "Введите номер группы прав доступа:" << "\n";
    cin >> position;

    string sqlQuery = "insert into `users` (`lastName`,`firstName`,`patronymic`,`position`) values('" + name + "','" + lastName + "','" + patronymic + "'," + to_string(position) + ")";
    
    db.Query(sqlQuery);//вызов метода Query (запрос к базе данных) класса DataBase 


    ////соединение с базой данный MySQL и вывод оттуда данных
    //cout << "Вывод значений базы данных crmbase: " << "\n";

    //MYSQL* conn;
    //MYSQL_RES* res;
    //MYSQL_ROW row;

    //int i = 0;

    //// Получаем дескриптор соединения
    //conn = mysql_init(NULL);
    //if (conn == NULL)
    //{
    //    // Если дескриптор не получен – выводим сообщение об ошибке
    //    fprintf(stderr, "Ошибка: MySQL дескриптор не создан\n");
    //    //exit(1); //Если используется оконное приложение
    //}
    //// Подключаемся к серверу
    //if (!mysql_real_connect(conn, "localhost", "root", "", "crmbase", NULL, NULL, 0))
    //{
    //    // Если нет возможности установить соединение с сервером
    //    // базы данных выводим сообщение об ошибке
    //    fprintf(stderr, "Ошибка: Нет соединения с базой данных %s\n", mysql_error(conn));
    //}
    //else
    //{
    //    // Если соединение успешно установлено выводим фразу - "успешно!"
    //    fprintf(stdout, "Соединение с базой MySQL успешно!\n");
    //}
    //mysql_set_character_set(conn, "cp1251");//для отображения Кириллицы
    ////Смотрим изменилась ли кодировка на нужную, по умалчанию идёт latin1
    //cout << "кодировка: " << mysql_character_set_name(conn) << endl;

    //mysql_query(conn, "SELECT idUser, lastName, firstName, patronymic, position FROM users"); //Делаем запрос "idUser, lastName, firstName, patronymic, position" к таблице по имени "users" =)

    //if (res = mysql_store_result(conn)) {
    //    while (row = mysql_fetch_row(res)) {
    //        for (i = 0; i < mysql_num_fields(res); i++) {
    //            cout << row[i] << "\n"; //Выводим все что есть в базе через цикл
    //        }
    //        cout << "\n";
    //    }

    //}
    //else fprintf(stderr, "%s\n", mysql_error(conn));

    //// Закрываем соединение с сервером базы данных
    //mysql_close(conn);

}