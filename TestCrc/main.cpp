#include <UnitTest++/UnitTest++.h>
#include "crc32.h"
SUITE(FileTest)
{
    TEST(ValidFile)
    {
        const unsigned long polynom=0x04C11DB7;
        string filename="/home/student/test.txt";
        calculatorCrc crc(polynom,filename);
        CHECK(true);
    }
    
    TEST(EmptyFileName)
    {
        const unsigned long polynom=0x04C11DB7;
        CHECK_THROW(calculatorCrc crc(polynom,""),error);
        
    }
    
    TEST(NoExtension)
    {
        const unsigned long polynom=0x04C11DB7;
        CHECK_THROW(calculatorCrc crc(polynom,"/home/student/test"), error);
    }
    
    TEST(UncorrectlyFileName)
    {
        const unsigned long polynom=0x04C11DB7;
        CHECK_THROW(calculatorCrc crc(polynom, "73-=043s;9171ks;"), error);
    }
    
    TEST(NoneFile)
    {
        const unsigned long polynom=0x04C11DB7;
        string filename="/home/student/ulala.txt";
        CHECK_THROW(calculatorCrc crc(polynom, filename), error);
    }
    
    TEST(NoPath) 
    {
        const unsigned long polynom=0x04C11DB7;
        string filename="true.txt";
        CHECK_THROW(calculatorCrc crc(polynom, filename), error);
    }

}

SUITE(TestCRC)
{
    TEST(NormalString)
    {
        const unsigned long polynom=0x04C11DB7;
        string filename="/home/student/file.txt";
        calculatorCrc crc(polynom,filename);
        CHECK_EQUAL(0x875b0920, crc.FileRead(filename,polynom));
    }
    
    TEST(EmptyString)
    {
        const unsigned long polynom=0x04C11DB7;
        string filename="/home/student/file2.txt";
        calculatorCrc crc(polynom,filename);
        CHECK_THROW(crc.FileRead(filename,polynom), error);
    }
    

}

int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}
