#ifndef TEST_H_DEFINED
#define TEST_H_DEFINED

#include "main.h"
#include "file.h"
#include "generate.h"
#include "calculate.h"
#include <chrono>

// -------------------------------------------------------
// testGenerateStudentai — iškviečiama iš meniu (pasirinkimas 6)
// Testuoja studentų failo generavimą su n studentų.
// -------------------------------------------------------
template<typename Container>
void testGenerateStudentai(int n)
{
    std::cout << "=== Studentų failo generavimo testavimas: " << n << " studentų ===\n";
    auto start = std::chrono::high_resolution_clock::now();
    Container studentai = generateStudentai<Container>(n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "  Generavimas: " << elapsed.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    writeStudentaiListToFile<Container>(studentai, "teststudentai" + std::to_string(n) + ".txt");
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "  Išvedimas į failą: " << elapsed.count() << " s\n";
}

// -------------------------------------------------------
// testData — iškviečiama iš meniu (pasirinkimas 7)
// Testuoja studentų duomenų apdorojimą su n studentų.
// -------------------------------------------------------
template<typename Container>
void testData(int n)
{
    Container studentai;

    auto startTotal = std::chrono::high_resolution_clock::now();
    std::cout << "Pradedamas testavimas su " << n << " studentų duomenimis.\n";
    std::cout << "------------------------------------------------------------\n";

    auto start = std::chrono::high_resolution_clock::now();

    studentai = readStudentaiFromFile<Container>("data/studentai" + std::to_string(n) + ".txt");
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << n << " failo skaitymas užtruko: " << elapsed.count() << " sekundžių.\n";

    calculateGalutinis(studentai, namuDarbaiSvertis, egzaminasSvertis);
    sortStudentai(studentai, '4');

    auto start2 = std::chrono::high_resolution_clock::now();

    splitResult<Container> result = splitStudentai<Container>(studentai);

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;
    std::cout << n << " skirstymas į kietiakai ir vargsiukai užtruko: " << elapsed2.count() << " sekundžių.\n";

    auto start3 = std::chrono::high_resolution_clock::now();
    writeStudentaiListToFile<Container>(result.kietiakai, "testkietiakai" + std::to_string(n) + ".txt");
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed3 = end3 - start3;
    std::cout << n << " Kietiakai failo generavimas užtruko: " << elapsed3.count() << " sekundžių.\n";
    
    auto start4 = std::chrono::high_resolution_clock::now();
    writeStudentaiListToFile<Container>(result.vargsiukai, "testvargsiukai" + std::to_string(n) + ".txt");
    auto end4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed4 = end4 - start4;
    auto endTotal = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTotal = endTotal - startTotal;
    std::cout << n << " Vargsiukai failo generavimas užtruko: " << elapsed4.count() << " sekundžių.\n";
    std::cout << n << " Visas testavimas užtruko: " << elapsedTotal.count() << " sekundžių.\n\n";   
}

#endif