#include <iostream>
#include "help.h"
#include <fstream>
#include "crc32.h"
#include <cstdlib>
using namespace std;
int main()
{
    string exit="/exit";
    string crc32="/crc";
    string help="/help";
    string mode;
    cout<<"Добрый день, данная программа вычисляет значение CRC32 (контрольной суммы) по стандарту IEEE-802.3.\n";
    Client helping;
    helping.help();
    string filename;
    unsigned long polynom = 0x04C11DB7;
    do {
        try {
            cout<<"Выберите режим работы: ";
            cin>>mode;
            if(mode==crc32) {
                cout<<"Введите полный путь до файла: ";
                cin.get();
                getline(cin,filename);
                calculatorCrc crc(polynom, filename);
                cout<<"Контрольная сумма равна: "<<hex<<crc.FileRead(filename, polynom)<<endl;
            }
            if(mode==exit) {
                cout<<"Завершение программы..."<<endl;
                return 0;
            }
            if(mode==help) {
                Client help;
                help.help();
            }
            if((mode!=crc32) and (mode!=exit)) {
                string choice;
                cout<<"Для того чтобы узнать используемые команды, воспользуйтесь справкой  с помощью команды \"/help\""<<endl;
                cout<<"Либо введите \"/no\" для продолжения работы с программой"<<endl;
                cin>>choice;
                if(choice==help) {
                    Client help;
                    help.help();
                }
            }

        } catch(error& e) {
            cerr<<e.what()<<endl;
        }

    } while (mode!=exit);
    return 0;

}
