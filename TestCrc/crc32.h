#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class calculatorCrc
{
private:
     unsigned long polynom;
     string filename;
public:
    calculatorCrc()=delete;
    calculatorCrc(const unsigned long pol, string filename);
    unsigned long FileRead(string filename, const unsigned long polynom);
    unsigned long calculateCRC(const char *message, unsigned long len, unsigned long polynom);

};


class error: public invalid_argument
{
public:
    explicit error (const string& what_arg):
        invalid_argument(what_arg) {}
    explicit error (const char* what_arg):
        invalid_argument(what_arg) {}

};
