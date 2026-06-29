#include "output.h"

void outputStudentai(const std::vector<studentas> &studentai, char choice)
{
    switch (choice)
    {
        case '1':
            printStudentaiVector(studentai);
            break;
        case '2':
            {
                std::string outputFileName = enterOutputFileName();
                writeStudentaiToFile(studentai, outputFileName);
            }
            break;
        default:
            throw std::runtime_error("Neteisingas pasirinkimas išvesties formatui.");
    }
}