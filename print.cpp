#include "print.h"

void printWelcome()
{
    std::cout << "\n------------------------------\n";
    std::cout << " Studentų informacinė sistema \n";
    std::cout << "------------------------------\n\n";
}

void printNameAsk()
{
    std::cout << "Įveskite naujus studentus.\n";
}

void printStudentaiVector(const std::vector<studentas> &studentai)
{
    if (studentai.empty())
        throw std::runtime_error("Studentų sąrašas tuščias — nėra ko spausdinti.");
    
    std::cout << std::left << std::setw(20) << "Vardas"
        << std::left << std::setw(20) << "Pavardė"
        << std::left << std::setw(20) << "Galutinis (Vid.)"
        << std::left << std::setw(20) << "Galutinis (Med.)\n";
    std::cout << "-----------------------------------------------------------------------\n";
    for(const auto &s : studentai)
    {
        std::cout << std::left << std::setw(20) << s.vardas
            << std::left << std::setw(20) << s.pavarde
            << std::left << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisVid
            << std::left << std::setw(20) << s.galutinisMed << "\n";
    }
}
