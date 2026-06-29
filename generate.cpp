#include "generate.h"

std::mt19937 getRng()
{
    static std::mt19937 rng(std::random_device{}());
    return rng;
}

std::vector<studentas> generateStudentai(int n)
{
    std::vector<studentas> studentai;
    std::vector<std::string> firstNames = generateStudentFirstNames(n);
    std::vector<std::string> surnames = generateStudentSurnames(n);
    for (int i = 0; i < n; i++)
    {
        studentas s;
        s.vardas = firstNames[i];
        s.pavarde = surnames[i];
        int m = generateNumberOfPazymys();
        s.namuDarbai = generatePazymiai(m);
        s.egzaminas = generatePazymiai(1)[0];
        studentai.push_back(s);
    }
    return studentai;
}

studentas* generateStudentaiArray(int n)
{
    studentas* studentai = new studentas[n];
    std::vector<std::string> firstNames = generateStudentFirstNames(n);
    std::vector<std::string> surnames = generateStudentSurnames(n);
    for (int i = 0; i < n; i++)
    {
        studentai[i].vardas = firstNames[i];
        studentai[i].pavarde = surnames[i];
        int m = generateNumberOfPazymys();
        studentai[i].namuDarbai = generatePazymiai(m);
        studentai[i].egzaminas = generatePazymiai(1)[0];
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
        s.egzaminas = generatePazymiai(1)[0];
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
        studentai[i].egzaminas = generatePazymiai(1)[0];
    }
    return studentai;
}

std::vector<std::string> generateStudentFirstNames(int n)
{
    std::vector<std::string> firstNames;
    std::uniform_int_distribution<int> dist(0, static_cast<int>(lithuanianNames.size()) - 1);
    std::mt19937 rng(getRng());
    for (int i = 0; i < n; i++)
    {
        firstNames.push_back(lithuanianNames[dist(rng)]);
    }
    return firstNames;
}

std::vector<std::string> generateStudentSurnames(int n)
{
    std::vector<std::string> surnames;
    std::uniform_int_distribution<int> dist(0, static_cast<int>(lithuanianSurnames.size()) - 1);
    std::mt19937 rng(getRng());
    for (int i = 0; i < n; i++)
    {
        surnames.push_back(lithuanianSurnames[dist(rng)]);
    }
    return surnames;
}

int generateNumberOfPazymys()
{
    std::uniform_int_distribution<int> dist(0, 10);
    std::mt19937 rng(getRng());
    return dist(rng);
}

std::vector<int> generatePazymiai(int m) // m - pažymių skaičius
{
    std::vector<int> tmp;
    std::uniform_int_distribution<int> dist(minPazymys, maxPazymys);
    std::mt19937 rng(std::random_device{}());
    for(int i{0} ; i < m ; i++)
    {
        tmp.push_back(dist(rng));
    }
    return tmp;
}