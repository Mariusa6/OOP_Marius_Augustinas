#include "main.h"

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


std::vector<studentas> readStudentaiFromFile(const std::string &filename)
{
    std::vector<studentas> studentai;
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Nepavyko atidaryti failo: " << filename << std::endl;
        return studentai;
    }

    std::string line;

    // Read header to determine number of ND columns
    if (!std::getline(file, line))
        return studentai;

    std::istringstream headerStream(line);
    std::string token;
    int ndCount = 0;
    while (headerStream >> token)
    {
        if (token.find("ND") != std::string::npos)
            ndCount++;
    }

    // Read student rows
    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        std::istringstream ss(line);
        studentas s;

        ss >> s.vardas >> s.pavarde;

        for (int i = 0; i < ndCount; i++)
        {
            int nd;
            if (ss >> nd)
                s.namuDarbai.push_back(nd);
        }

        ss >> s.egzaminas;

        studentai.push_back(s);
    }
    file.close();
    return studentai;
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
    {
        std::cerr << "Nepavyko sukurti failo: " << filename << std::endl;
        return;
    }

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
