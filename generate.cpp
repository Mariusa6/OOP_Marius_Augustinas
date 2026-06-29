#include "generate.h"

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

studentas* generateStudentaiArray(int n)
{
    studentas* studentai = new studentas[n];
    for (int i = 0; i < n; i++)
    {
        studentai[i].vardas = generateStudentName();
        studentai[i].pavarde = generateStudentSurname();
        int m = generateNumberOfPazymys();
        studentai[i].namuDarbai = generatePazymiai(m);
        studentai[i].egzaminas = generatePazymys();
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

studentas* generateOnlyPazymiaiArray(int n)
{
    studentas* studentai = new studentas[n];
    for (int i = 0; i < n; i++)
    {
        studentai[i].vardas = enterName(i + 1);
        studentai[i].pavarde = enterSurname(i + 1);
        int m = generateNumberOfPazymys();
        studentai[i].namuDarbai = generatePazymiai(m);
        studentai[i].egzaminas = generatePazymys();
    }
    return studentai;
}

std::string generateStudentName()
{
    std::uniform_int_distribution<int> dist(0, static_cast<int>(lithuanianNames.size()) - 1);
    std::mt19937 rng(std::random_device{}());
    return lithuanianNames[dist(rng)];
}

std::string generateStudentSurname()
{
    std::uniform_int_distribution<int> dist(0, static_cast<int>(lithuanianSurnames.size()) - 1);
    std::mt19937 rng(std::random_device{}());
    return lithuanianSurnames[dist(rng)];
}

int generateNumberOfPazymys()
{
    std::uniform_int_distribution<int> dist(0, 10);
    std::mt19937 rng(std::random_device{}());
    return dist(rng);
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
    std::uniform_int_distribution<int> dist(minPazymys, maxPazymys);
    std::mt19937 rng(std::random_device{}());
    return dist(rng);
}
