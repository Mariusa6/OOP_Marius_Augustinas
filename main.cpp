#include "main.h"
#include "calculate.h"
#include "file.h"
#include "enter.h"
#include "generate.h"
#include "output.h"
#include "test.h"

template<typename Container>
void runProgram()
{
    char choice {};
    char sortChoice {};
    char outputChoice {};
    Container studentai {};
    splitResult<Container> result {};

    while(true)
    {
        choice = askMenuChoice();
        switch (choice)
        {
            case '0':
                std::cout << "Programa baigta.\n";
                return;
            case '1':
                studentai = enterStudentai<Container>();
                calculateGalutinis<Container>(studentai, namuDarbaiSvertis, egzaminasSvertis);
                sortChoice = askSortBy();
                sortStudentai<Container>(studentai, sortChoice);
                result = splitStudentai(studentai);
                outputChoice = askOutputChoice();
                outputStudentai<Container>(result.kietiakai, outputChoice);
                outputStudentai<Container>(result.vargsiukai, outputChoice);
                break;
            case '2':
                studentai = generateOnlyPazymiai<Container>(enterNumberOfStudents());
                calculateGalutinis<Container>(studentai, namuDarbaiSvertis, egzaminasSvertis);
                sortChoice = askSortBy();
                sortStudentai<Container>(studentai, sortChoice);
                result = splitStudentai<Container>(studentai);
                outputChoice = askOutputChoice();
                outputStudentai<Container>(result.kietiakai, outputChoice);
                outputStudentai<Container>(result.vargsiukai, outputChoice);
                break;
            case '3':
                studentai = generateStudentai<Container>(enterNumberOfStudents());
                calculateGalutinis<Container>(studentai, namuDarbaiSvertis, egzaminasSvertis);
                sortChoice = askSortBy();
                sortStudentai<Container>(studentai, sortChoice);
                result = splitStudentai<Container>(studentai);
                outputChoice = askOutputChoice();
                outputStudentai<Container>(result.kietiakai, outputChoice);
                outputStudentai<Container>(result.vargsiukai, outputChoice);
                break;
            case '4':
                studentai = readStudentaiFromFile<Container>(enterFileName());
                calculateGalutinis<Container>(studentai, namuDarbaiSvertis, egzaminasSvertis);
                sortChoice = askSortBy();
                sortStudentai<Container>(studentai, sortChoice);
                result = splitStudentai<Container>(studentai);
                outputChoice = askOutputChoice();
                outputStudentai<Container>(result.kietiakai, outputChoice);
                outputStudentai<Container>(result.vargsiukai, outputChoice);
                break;
            case '5':
                studentai = generateStudentai<Container>(enterNumberOfStudents());
                writeStudentaiListToFile<Container>(studentai, enterOutputFileName());
                break;
            case '6':
                testGenerateStudentai<Container>(1000);
                testGenerateStudentai<Container>(10000);
                testGenerateStudentai<Container>(100000);
                testGenerateStudentai<Container>(1000000);
                testGenerateStudentai<Container>(10000000);
                break;
            case '7':
                testData<Container>(1000);
                testData<Container>(10000);
                testData<Container>(100000);
                testData<Container>(1000000);
                testData<Container>(10000000);
                break;
            case '8':
                testContainers(1000);
                testContainers(10000);
                testContainers(100000);
                testContainers(1000000);
                testContainers(10000000);
                break;
            default:
                std::cout << "Neteisingas pasirinkimas. Bandykite dar kartą.\n";
                break;
        }
    }
}

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    printWelcome();

    try
    {
        switch (askContainerChoice())
        {
            case '1':
                runProgram<std::vector<studentas>>();
                break;
            case '2':
                runProgram<std::list<studentas>>();
                break;
            case '3':
                runProgram<std::deque<studentas>>();
                break;
            default:
                std::cout << "Neteisingas pasirinkimas. Programa baigta.\n";
                return 1;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Klaida: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
