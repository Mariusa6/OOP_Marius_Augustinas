#include "test.h"

void testGenerateStudentai(int n)
{
    std::vector<studentas> studentai {};
    studentai = generateStudentai(n);
    auto start = std::chrono::high_resolution_clock::now();
    writeStudentaiListToFile(studentai, "teststudentai" + std::to_string(n) + ".txt");
    studentai.clear();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << n << " Studentų failo generavimas užtruko: " << elapsed.count() << " sekundžių.\n";
}

void testData(int n)
{
    std::vector<studentas> studentai {};
    auto start = std::chrono::high_resolution_clock::now();
    studentai = readStudentaiFromFile("data/studentai" + std::to_string(n) + ".txt");
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << n << " Studentų failo skaitymas užtruko: " << elapsed.count() << " sekundžių.\n";
    calculateGalutinisVector(studentai, namuDarbaiSvertis, egzaminasSvertis);
    sortStudentai(studentai, '4');
    auto start2 = std::chrono::high_resolution_clock::now();
    splitResult result = splitStudentai(studentai);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;
    std::cout << n << " Studentų skirstymas į kietiakai ir vargsiukai užtruko: " << elapsed2.count() << " sekundžių.\n";
}
