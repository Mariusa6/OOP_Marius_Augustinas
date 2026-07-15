#include "main.h"
#include "calculate.h"

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
    std::vector<studentas> studentaiVector {};
    std::list<studentas> studentaiList {};
    std::deque<studentas> studentaiDeque {};
    splitResult<std::vector<studentas>> resultVector {};
    splitResult<std::list<studentas>> resultList {};
    splitResult<std::deque<studentas>> resultDeque {};
    std::string inputFileName {};
    std::string outputFileName {};
    try
    {
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
                    studentaiVector = enterStudentaiVector();
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
                    studentaiVector = generateOnlyPazymiaiVector(n);
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
                    studentaiVector = generateStudentaiVector(n);
                    calculateGalutinis(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
                    sortChoice = askSortBy();
                    sortStudentai(studentaiVector, sortChoice);
                    resultVector = splitStudentai(studentaiVector);
                    outputChoice = askOutputChoice();
                    outputStudentai(resultVector.kietiakai, outputChoice);
                    outputStudentai(resultVector.vargsiukai, outputChoice);
                    break;
                case '4':
                    inputFileName = enterFileName();
                    studentaiVector = readStudentaiFromFileVector(inputFileName);
                    calculateGalutinis(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
                    sortChoice = askSortBy();
                    sortStudentai(studentaiVector, sortChoice);
                    resultVector = splitStudentai(studentaiVector);
                    outputChoice = askOutputChoice();
                    outputStudentai(resultVector.kietiakai, outputChoice);
                    outputStudentai(resultVector.vargsiukai, outputChoice);
                    break;
                case '5':
                    studentaiVector = generateStudentaiVector(enterNumberOfStudents());
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
