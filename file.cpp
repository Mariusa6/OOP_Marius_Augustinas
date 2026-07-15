#include "file.h"

std::string enterFileName()
{
    std::string tmp;
    std::cout << "Įveskite failo pavadinimą (su .txt plėtiniu): ";
    while (!(std::cin >> tmp) || tmp.size() < 5 || tmp.substr(tmp.size() - 4) != ".txt")
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Netinkama įvestis. Įveskite failo pavadinimą su .txt plėtiniu: ";
    }
    return tmp;
}

std::string enterOutputFileName()
{
    std::string tmp;
    std::cout << "Įveskite išvesties failo pavadinimą (su .txt plėtiniu): ";
    while (!(std::cin >> tmp) || tmp.size() < 5 || tmp.substr(tmp.size() - 4) != ".txt")
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Netinkama įvestis. Įveskite išvesties failo pavadinimą su .txt plėtiniu: ";
    }
    return tmp;
}

void writeStudentaiToFile(const std::vector<studentas> &studentai, const std::string &filename)
{
    std::ofstream file(filename);
    
    if (!file.is_open())
        throw std::runtime_error("Nepavyko sukurti failo: " + filename);

    file << "Vardas              Pavardė             Galutinis (Vid.)    Galutinis (Med.)\n";
    file << "----------------------------------------------------------------------------\n";

    for (const auto &s : studentai)
    {
        file << std::left << std::setw(20) << s.vardas 
        << std::left << std::setw(20) << s.pavarde 
        << std::left << std::setw(20) << s.galutinisVid 
        << std::left << std::setw(20) << s.galutinisMed << "\n";
    }
    
    file.close();
}

void writeStudentaiListToFile(const std::vector<studentas> &studentai, const std::string &filename)
{
    std::ofstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Nepavyko sukurti failo: " + filename);
    
    file << std::left << std::setw(25) << "Vardas" 
         << std::left << std::setw(25) << "Pavardė";
    for (int i = 1; i <= NUMBER_OF_PAZYMYS; ++i)
    {
        file << std::right << std::setw(10) << ("ND" + std::to_string(i));
    }
    file << std::right << std::setw(10) << "Egzaminas" << "\n";

    for (const auto &s : studentai)
    {
        file << std::left << std::setw(25) << s.vardas 
             << std::left << std::setw(25) << s.pavarde;
        for (const auto &nd : s.namuDarbai)
        {
            file << std::right << std::setw(10) << nd;
        }
        file << std::right << std::setw(10) << s.egzaminas << "\n";
    }
}
