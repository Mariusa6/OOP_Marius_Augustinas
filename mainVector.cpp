#include "main.h"

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    printWelcome();
    int n {};
    char choice {};
    char sortChoice {};
    char outputChoice {};
    std::vector<studentas> studentaiVector {};
    choice = askMenuChoice();
    std::string inputFileName {};
    std::string outputFileName {};
    try
    {
        switch (choice)
        {
            case '1':
                studentaiVector = enterStudentaiVector();
                calculateGalutinisVector(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
                outputChoice = askOutputChoice();
                outputStudentai(studentaiVector, outputChoice);
                break;
            case '2':
                n = enterNumberOfStudents();
                studentaiVector = generateOnlyPazymiai(n);
                calculateGalutinisVector(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
                outputChoice = askOutputChoice();
                outputStudentai(studentaiVector, outputChoice);
                break;
            case '3':
                n = enterNumberOfStudents();
                studentaiVector = generateStudentai(n);
                calculateGalutinisVector(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
                sortChoice = askSortBy();
                sortStudentai(studentaiVector, sortChoice);
                outputChoice = askOutputChoice();
                outputStudentai(studentaiVector, outputChoice);
                break;
            case '4':
                inputFileName = enterFileName();
                studentaiVector = readStudentaiFromFile(inputFileName);
                calculateGalutinisVector(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
                sortChoice = askSortBy();
                sortStudentai(studentaiVector, sortChoice);
                outputChoice = askOutputChoice();
                outputStudentai(studentaiVector, outputChoice);
                break;
            case '5':
                std::cout << "Programa baigta.\n";
                break;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Klaida: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
