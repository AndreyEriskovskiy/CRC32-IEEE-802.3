/**
 * @file crc32.h 
 * @author Ерисковский А.И
 * @date 11/06/21
 * @version 1.0
 * @brief Вычисление контрольной суммы CRC32-IEEE 802.3
 * @copyright ИБСТ ПГУ
 * @warning Это учебный пример
 */
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
/**
 * @class calculatorCrc
 * @brief Описание класса calculatorCRC
 * @details Класс реализует вычисление контрольной суммы CRC с использованием образуещего полинома: 0x04C11DB7
 */
class calculatorCrc
{
private:
/// Атрибут, хранящий числовое значение образующего полинома.
     unsigned long polynom;
/// Атрибут, хранящий полный путь к файлу, из которого будут читаться данные.
     string filename;
public:
/// Запрет объявления объекта класса без параметров
    calculatorCrc()=delete;
/**
 * @brief Конструктор, инициализирующий значение образующего полинома.
 * @details В данном конструкторе возбуждаются исключительные ситуации, связанные с возможными ошибками с файлами.
 * @param filename - полный путь к файлу
 * @param polynom - значение образующего полинома
 */
    calculatorCrc(const unsigned long pol, string filename);
/**
 * @brief Метод класса FileRead 
 * @details Метод открывает файл, для которого будет вычислена контрольная сумма, определяет его размер, 
 * @details записывает данные в буфер и вызывает метод, вычисляющий значение контрольной суммы
 * @param filename - полный путь к файлу
 * @param polynom - значение образующего полинома
 * @return Возвращает результат работы функции "calculateCRC", вычисляющей значение CRC.
 */
    unsigned long FileRead(string filename, const unsigned long polynom);
/**
 * @brief Метод класса calculateCRC
 * @details Рассчитывает значение CRC по следующему алгоритму:
 * @details  1 - В регистр заносится начальное значение 0xFFFFFFFF (или 32 единичных бита);
 * @details  2 - Выполняется цикл c числом повторений, равному количеству байт в сообщении;
 * @details  3 - Текущее значение регистра складываается по модулю 2 (операция XOR) с каждым байтом сообщения;
 * @details  4 - Запускается вложенный цикл, в котором проверяется каждый бит каждого байта сообщения;
 * @details  5 - Если выбранный бит равен единице: регистр сдвигается влево на 1 бит, затем складывается по модулю 2 (операция XOR) со значением образующего полинома;
 * @details  6 - Если выбранный бит не равен единице: регистр сдвигается влево на 1 бит без дополнительных действий;
 * @details  7 - По окончании основного и вложенного циклов инвертируются биты содержимого регистра.
 * @param message - массив, состоящий из байтов сообщения.
 * @param len - длина массива байтов сообщения.
 * @param polynom - значение образующего полинома (0x04C11DB7).
 * @return Метод возвращает вычисленное значение CRC.
 */
    unsigned long calculateCRC(const char *message, unsigned long len, unsigned long polynom);

};
/**
 * @class error
 * @brief Описание класса error
 * @details Данный класс предназначен для возбуждения и обработки ошибок, которые могут возникнуть при взаимодействии с программой.
 */
class error: public invalid_argument
{
public:
/**
 * @brief Конструктор принимает на вход строку и возбуждает исключение
 * @param what_arg
 */
    explicit error (const string& what_arg):
        invalid_argument(what_arg) {}
/**
 * @brief Конструктор принимает на вход си-строку и возбуждает исключение
 * @param what_arg
 */
    explicit error (const char* what_arg):
        invalid_argument(what_arg) {}

}; 
