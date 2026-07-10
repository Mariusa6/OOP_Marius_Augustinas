#include "generate.h"

std::mt19937& getRng()
{
    static std::mt19937 rng(std::random_device{}());
    return rng;
}

std::vector<studentas> generateStudentaiVector(int n)
{
    std::vector<studentas> studentai;
    studentai.reserve(n);
    for (int i = 0; i < n; i++)
    {
        studentas s;
        s.vardas = "VardasNR" + std::to_string(i + 1);
        s.pavarde = "PavardeNR" + std::to_string(i + 1);
        int m = NUMBER_OF_PAZYMYS;
        s.namuDarbai = generatePazymiai(m);
        s.egzaminas = generatePazymiai(1)[0];
        studentai.push_back(s);
    }
    return studentai;
}

std::vector<studentas> generateOnlyPazymiaiVector(int n)
{
    std::vector<studentas> studentai;
    studentai.reserve(n);
    for (int i = 0; i < n; i++)
    {
        studentas s;
        s.vardas = enterName(i + 1);
        s.pavarde = enterSurname(i + 1);
        int m = NUMBER_OF_PAZYMYS;
        s.namuDarbai = generatePazymiai(m);
        s.egzaminas = generatePazymiai(1)[0];
        studentai.push_back(s);
    }
    return studentai;
}

std::vector<int> generatePazymiai(int m) // m - pažymių skaičius
{
    std::vector<int> tmp;
    std::uniform_int_distribution<int> dist(minPazymys, maxPazymys);
    std::mt19937 &rng = getRng();
    for(int i{0} ; i < m ; i++)
    {
        tmp.push_back(dist(rng));
    }
    return tmp;
}