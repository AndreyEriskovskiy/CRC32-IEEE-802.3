#include "crc32.h"

calculatorCrc::calculatorCrc(const unsigned long pol, string file)
{

    if(file.empty())
        throw error("Пустое имя файла");


    if(file.find('.')==string::npos)
        throw error("Некорректное имя файла");

    int pos=file.rfind('.');
    if(file.substr(pos+1).empty())
        throw error("Не указано расширение файла");

    ifstream fin(file, ios::binary);
    if(!(fin.good()))
        throw error("Ошибка открытия файла");
    fin.close();

    for(auto c:file) {
        if(c<=32 || c>=127)
            throw error("Недопустимое название файла");
        break;
    }

}


unsigned long calculatorCrc::calculateCRC(const char *message, unsigned long len, const unsigned long polynom)
{
    if(message[0]=='\0')
        throw error("Пустая строка");
    unsigned crc = 0xFFFFFFFF; // инициализация CRC начальным значением
    for(unsigned long i=0; i<len; i++) { // перебор всех байтов сообщения
        crc= crc^(message[i]<<24) ; // сложение каждого байта сообщения с текущим значением CRC
        for (int j=0; j<8; j++) { // перебор всех битов каждого байта
            if(crc & (1<<31)) // Проверка старшего бита (равен ли он единице)
                crc = (crc<<1) ^ polynom; // сдвиг битов влево в сторону старшего бита, сложение по модулю 2 со значением образующего полинома
            else
                crc = crc<<1; // старший бит заполняется нулём
        }
    }
    return crc^0xFFFFFFFF; // финальный XOR (инверсия битов) CRC

}

unsigned long calculatorCrc::FileRead(string filename, const unsigned long polynom)
{
    ifstream fin;
    fin.open(filename, ios::binary);
    fin.seekg(0,ios::end);
    int size=fin.tellg();
    fin.seekg(0,ios::beg);
    char* message=new char[size];
    fin.read(message,size);
    return calculateCRC(message,fin.gcount(),polynom);
    delete[] message;
    fin.close();
}
