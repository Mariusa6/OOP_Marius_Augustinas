#include "main.h"

std::vector<studentas> generateStudentai(int n)
{
    std::vector<studentas> studentai;
    for (int i = 0; i < n; i++)
    {
        studentas s;
        s.vardas = generateStudentName();
        s.pavarde = generateStudentSurname();
        int m = generateNumberOfPazymys();
        s.namuDarbai = generatePazymiai(m);
        s.egzaminas = generatePazymys();
        studentai.push_back(s);
    }
    return studentai;
}

std::vector<studentas> generateOnlyPazymiai(int n)
{
    std::vector<studentas> studentai;
    for (int i = 0; i < n; i++)
    {
        studentas s;
        s.vardas = enterName(i + 1);
        s.pavarde = enterSurname(i + 1);
        int m = generateNumberOfPazymys();
        s.namuDarbai = generatePazymiai(m);
        s.egzaminas = generatePazymys();
        studentai.push_back(s);
    }
    return studentai;
}

std::string generateStudentName()
{
    return lithuanianNames[std::mt19937{std::random_device{}()}() % lithuanianNames.size()];
}

std::string generateStudentSurname()
{
    return lithuanianSurnames[std::mt19937{std::random_device{}()}() % lithuanianSurnames.size()];
}

int generateNumberOfPazymys()
{
    return std::mt19937{std::random_device{}()}() % 10 + 1;
}

std::vector<int> generatePazymiai(int m) // m - pažymių skaičius
{
    std::vector<int> tmp;
    for(int i{0} ; i < m ; i++)
    {
        tmp.push_back(generatePazymys());
    }
    return tmp;
}

int generatePazymys()
{
    return std::mt19937{std::random_device{}()}() % 10 + 1;
}
