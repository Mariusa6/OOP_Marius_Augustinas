#include "main.h"

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
    splitResult result {};
    std::string inputFileName {};
    std::string outputFileName {};
    try
    {
        while(menuLoop)
        {
            choice = askMenuChoice();
            switch (choice)
            {
                case '1':
                    studentaiVector = enterStudentaiVector();
                    calculateGalutinisVector(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
                    sortChoice = askSortBy();
                    sortStudentai(studentaiVector, sortChoice);
                    result = splitStudentai(studentaiVector);
                    outputChoice = askOutputChoice();
                    outputStudentai(result.kietiakai, outputChoice);
                    outputStudentai(result.vargsiukai, outputChoice);
                    break;
                case '2':
                    n = enterNumberOfStudents();
                    studentaiVector = generateOnlyPazymiai(n);
                    calculateGalutinisVector(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
                    sortChoice = askSortBy();
                    sortStudentai(studentaiVector, sortChoice);
                    result = splitStudentai(studentaiVector);
                    outputChoice = askOutputChoice();
                    outputStudentai(result.kietiakai, outputChoice);
                    outputStudentai(result.vargsiukai, outputChoice);
                    break;
                case '3':
                    n = enterNumberOfStudents();
                    studentaiVector = generateStudentai(n);
                    calculateGalutinisVector(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
                    sortChoice = askSortBy();
                    sortStudentai(studentaiVector, sortChoice);
                    result = splitStudentai(studentaiVector);
                    outputChoice = askOutputChoice();
                    outputStudentai(result.kietiakai, outputChoice);
                    outputStudentai(result.vargsiukai, outputChoice);
                    break;
                case '4':
                    inputFileName = enterFileName();
                    studentaiVector = readStudentaiFromFile(inputFileName);
                    calculateGalutinisVector(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
                    sortChoice = askSortBy();
                    sortStudentai(studentaiVector, sortChoice);
                    result = splitStudentai(studentaiVector);
                    outputChoice = askOutputChoice();
                    outputStudentai(result.kietiakai, outputChoice);
                    outputStudentai(result.vargsiukai, outputChoice);
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
                    std::cout << "Programa baigta.\n";
                    menuLoop = false;
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
