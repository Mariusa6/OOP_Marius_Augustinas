#include "test.h"
#include "calculate.h"
#include "file.h"

void testGenerateStudentai(int n)
{
    std::vector<studentas> studentai {};
    studentai = generateStudentaiVector(n);
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

    auto startTotal = std::chrono::high_resolution_clock::now();
    std::cout << "Pradedamas testavimas su " << n << " studentų duomenimis.\n";
    std::cout << "------------------------------------------------------------\n";

    auto start = std::chrono::high_resolution_clock::now();

    studentai = readStudentaiFromFile<std::vector<studentas>>("data/studentai" + std::to_string(n) + ".txt");
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << n << " failo skaitymas užtruko: " << elapsed.count() << " sekundžių.\n";

    calculateGalutinis(studentai, namuDarbaiSvertis, egzaminasSvertis);
    sortStudentai(studentai, '4');

    auto start2 = std::chrono::high_resolution_clock::now();

    splitResult<std::vector<studentas>> result = splitStudentai(studentai);

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;
    std::cout << n << " skirstymas į kietiakai ir vargsiukai užtruko: " << elapsed2.count() << " sekundžių.\n";

    auto start3 = std::chrono::high_resolution_clock::now();
    writeStudentaiListToFile(result.kietiakai, "testkietiakai" + std::to_string(n) + ".txt");
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed3 = end3 - start3;
    std::cout << n << " Kietiakai failo generavimas užtruko: " << elapsed3.count() << " sekundžių.\n";
    
    auto start4 = std::chrono::high_resolution_clock::now();
    writeStudentaiListToFile(result.vargsiukai, "testvargsiukai" + std::to_string(n) + ".txt");
    auto end4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed4 = end4 - start4;
    auto endTotal = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTotal = endTotal - startTotal;
    std::cout << n << " Vargsiukai failo generavimas užtruko: " << elapsed4.count() << " sekundžių.\n";
    std::cout << n << " Visas testavimas užtruko: " << elapsedTotal.count() << " sekundžių.\n\n";
}
