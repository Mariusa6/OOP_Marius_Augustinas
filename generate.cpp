#include "generate.h"

std::mt19937& getRng()
{
    static std::mt19937 rng(std::random_device{}());
    return rng;
}

std::vector<studentas> generateStudentai(int n)
{
    std::vector<studentas> studentai;
    for (int i = 0; i < n; i++)
    {
        studentas s;
        s.vardas = "Vardas" + std::to_string(i + 1);
        s.pavarde = "Pavarde" + std::to_string(i + 1);
        int m = NUMBER_OF_PAZYMYS;
        s.namuDarbai = generatePazymiai(m);
        s.egzaminas = generatePazymiai(1)[0];
        studentai.push_back(s);
    }
    return studentai;
}

studentas* generateStudentaiArray(int n)
{
    studentas* studentai = new studentas[n];
    for (int i = 0; i < n; i++)
    {
        studentai[i].vardas = "Vardas" + std::to_string(i + 1);
        studentai[i].pavarde = "Pavarde" + std::to_string(i + 1);
        int m = NUMBER_OF_PAZYMYS;
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
        int m = NUMBER_OF_PAZYMYS;
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
        int m = NUMBER_OF_PAZYMYS;
        studentai[i].namuDarbai = generatePazymiai(m);
        studentai[i].egzaminas = generatePazymiai(1)[0];
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