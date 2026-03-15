#include "main.h"

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    printWelcome();
    int n {};
    char choice {};
    char sortChoice {};
    std::vector<studentas> studentaiVector {};
    choice = askMenuChoice();
    std::string inputFileName {};
    std::string outputFileName {};
    switch (choice)
    {
        case '1':
            studentaiVector = enterStudentaiVector();
            calculateGalutinisVector(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
            printStudentaiVector(studentaiVector);
            break;
        case '2':
            n = enterNumberOfStudents();
            studentaiVector = generateOnlyPazymiai(n);
            calculateGalutinisVector(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
            printStudentaiVector(studentaiVector);
            break;
        case '3':
            n = enterNumberOfStudents();
            studentaiVector = generateStudentai(n);
            calculateGalutinisVector(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
            sortChoice = askSortBy();
            sortStudentai(studentaiVector, sortChoice);
            printStudentaiVector(studentaiVector);
            break;
        case '4':
            inputFileName = enterFileName();
            studentaiVector = readStudentaiFromFile(inputFileName);
            calculateGalutinisVector(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
            sortChoice = askSortBy();
            sortStudentai(studentaiVector, sortChoice);
            outputFileName = enterOutputFileName();
            writeStudentaiToFile(studentaiVector, outputFileName);
            break;
        case '5':
            std::cout << "Programa baigta.\n";
            break;
    }
    return 0;
}
