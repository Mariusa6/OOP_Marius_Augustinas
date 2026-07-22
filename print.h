#ifndef PRINT_H_DEFINED
#define PRINT_H_DEFINED

#include "main.h"
#include <iostream> // cout, cin
#include <iomanip>  // setprecision, setw
#include <vector>   // vector
#include <stdexcept> // runtime_error

// -------------------------------------------------------
// printStudentai — išveda studentus į konsolę su antrašte.
// -------------------------------------------------------
template<typename Container>
void printStudentai(const Container &studentai)
{
    if (studentai.empty())
        throw std::runtime_error("Studentų sąrašas tuščias — nėra ko spausdinti.");
    
    std::cout << std::left << std::setw(20) << "Vardas"
        << std::left << std::setw(20) << "Pavardė"
        << std::left << std::setw(20) << "Galutinis (Vid.)"
        << std::left << std::setw(20) << "Galutinis (Med.)\n";
    std::cout << "-----------------------------------------------------------------------\n";
    for(auto &s : studentai)
    {
        std::cout << std::left << std::setw(20) << s.vardas
            << std::left << std::setw(20) << s.pavarde
            << std::left << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisVid
            << std::left << std::setw(20) << s.galutinisMed << "\n";
    }
}


#endif // PRINT_H_DEFINED