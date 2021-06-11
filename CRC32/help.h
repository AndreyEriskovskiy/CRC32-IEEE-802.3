/**
 * @file help.h
 * @author Ерисковский А.И
 * @version 1.0
 * @date 11/06/21
 * @copyright ИБСТ ПГУ
 * @warning Это учебный пример
 */
#pragma once
#include <iostream>
using namespace std;
/**
 * @class Client
 * @brief Данный класс выполняет функцию выдачи справки пользователю о режимах работы программы
 */
class Client
{
private:
/// Атрибут, содержащий справочную информацию
    const string helper= "Справочная информация:\n""/crc - вычисление контрольной суммы CRC32-IEEE 802.3\n""/exit - завершение работы программы\n""Пример правильной записи полного пути к файлу: /home/student/test1.txt";
public:
/// Метод, выводящий справочную информацию на экран
    void help();
};