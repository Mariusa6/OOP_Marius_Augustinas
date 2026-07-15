#include "main.h"
#include "calculate.h"
#include "file.h"

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    printWelcome();
    int n {};
    bool menuLoop = true;
    char choice {};
    char sortChoice {};
    char outputChoice {};
    char containerChoice {};
    std::vector<studentas> studentaiVector {};
    splitResult<std::vector<studentas>> resultVector {};
    try
    {
        containerChoice = askContainerChoice();

        if (containerChoice == '1')
            std::vector<studentas> studentai {};

        else if (containerChoice == '2')
            std::list<studentas> studentai {};

        else
            std::deque<studentas> studentai {};
            
        while(menuLoop)
        {
            choice = askMenuChoice();
            switch (choice)
            {
                case '0':
                    std::cout << "Programa baigta.\n";
                    menuLoop = false;
                    break;
                case '1':
                    studentaiVector = enterStudentai();
                    calculateGalutinis(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
                    sortChoice = askSortBy();
                    sortStudentai(studentaiVector, sortChoice);
                    resultVector = splitStudentai(studentaiVector);
                    outputChoice = askOutputChoice();
                    outputStudentai(resultVector.kietiakai, outputChoice);
                    outputStudentai(resultVector.vargsiukai, outputChoice);
                    break;
                case '2':
                    n = enterNumberOfStudents();
                    studentaiVector = generateOnlyPazymiai(n);
                    calculateGalutinis(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
                    sortChoice = askSortBy();
                    sortStudentai(studentaiVector, sortChoice);
                    resultVector = splitStudentai(studentaiVector);
                    outputChoice = askOutputChoice();
                    outputStudentai(resultVector.kietiakai, outputChoice);
                    outputStudentai(resultVector.vargsiukai, outputChoice);
                    break;
                case '3':
                    n = enterNumberOfStudents();
                    studentaiVector = generateStudentai(n);
                    calculateGalutinis(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
                    sortChoice = askSortBy();
                    sortStudentai(studentaiVector, sortChoice);
                    resultVector = splitStudentai(studentaiVector);
                    outputChoice = askOutputChoice();
                    outputStudentai(resultVector.kietiakai, outputChoice);
                    outputStudentai(resultVector.vargsiukai, outputChoice);
                    break;
                case '4':
                    studentaiVector = readStudentaiFromFile<std::vector<studentas>>(enterFileName());
                    calculateGalutinis(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
                    sortChoice = askSortBy();
                    sortStudentai(studentaiVector, sortChoice);
                    resultVector = splitStudentai(studentaiVector);
                    outputChoice = askOutputChoice();
                    outputStudentai(resultVector.kietiakai, outputChoice);
                    outputStudentai(resultVector.vargsiukai, outputChoice);
                    break;
                case '5':
                    studentaiVector = generateStudentai(enterNumberOfStudents());
                    writeStudentaiListToFile(studentaiVector, enterOutputFileName());
                    break;
                case '6':
                    testGenerateStudentai(1000);
                    testGenerateStudentai(10000);
                    testGenerateStudentai(100000);
                    testGenerateStudentai(1000000);
                    testGenerateStudentai(10000000);
                    break;
                case '7':
                    testData(1000);
                    testData(10000);
                    testData(100000);
                    testData(1000000);
                    testData(10000000);
                    break;
                case '8':
                    testContainers(1000);
                    testContainers(10000);
                    testContainers(100000);
                    testContainers(1000000);
                    testContainers(10000000);
                    break;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Klaida: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
