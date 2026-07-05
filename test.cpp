#include "test.h"

void testGenerateStudentai(int n)
{
    std::vector<studentas> studentai {};
    studentai = generateStudentai(n);
    auto start = std::chrono::high_resolution_clock::now();
    writeStudentaiListToFile(studentai, "teststudentai" + std::to_string(n) + ".txt");
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << n << "Studentų failo generavimas užtruko: " << elapsed.count() << " sekundžių.\n";
}