#include "test.h"
#include "calculate.h"
#include "file.h"

// -------------------------------------------------------
// Vidinis šablonas — naudojamas tik šiame faile.
// Matuoja tris žingsnius su pasirinktu konteineriu:
//   1. Nuskaitymas iš failo
//   2. Rikiavimas
//   3. Skirstymas į dvi grupes
// -------------------------------------------------------
template<typename Container>
static void testContainer(const std::string &label, const std::string &filename)
{
    
 
    std::cout << "  [" << label << "]\n";
 
    // 1. Nuskaitymas
    auto start = std::chrono::high_resolution_clock::now();
    Container studentai = readStudentaiFromFile<Container>(filename);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "    Nuskaitymas: " << elapsed.count() << " s\n";
 
    // Galutinių balų skaičiavimas (būtinas prieš rikiavimą, neįtraukiamas į matavimą)
    calculateGalutinis(studentai, namuDarbaiSvertis, egzaminasSvertis);
 
    // 2. Rikiavimas
    // vector/deque: std::sort  |  list: .sort()  (sprendžiama if constexpr calculate.h)
    auto start2 = std::chrono::high_resolution_clock::now();
    sortStudentai(studentai, '4');
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;
    std::cout << "    Rikiavimas:  " << elapsed2.count() << " s\n";
 
    // 3. Skirstymas į dvi grupes
    Container kietiakai, vargsiukai;
    auto start3 = std::chrono::high_resolution_clock::now();
    splitResult<Container> result = splitStudentai(studentai);
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed3 = end3 - start3;
    std::cout << "    Skirstymas:  " << elapsed3.count() << " s\n";
}
 
// -------------------------------------------------------
// testContainers — iškviečiama iš meniu (pasirinkimas 8)
// Testuoja tą patį failą su visais trimis konteineriais
// -------------------------------------------------------
void testContainers(int n)
{
    const std::string filename = "data/studentai" + std::to_string(n) + ".txt";
    std::cout << "=== Konteinerių palyginimas: " << n << " studentų ===\n";
    testContainer<std::vector<studentas>>("vector", filename);
    testContainer<std::list<studentas>>  ("list",   filename);
    testContainer<std::deque<studentas>> ("deque",  filename);
    std::cout << "\n";
}