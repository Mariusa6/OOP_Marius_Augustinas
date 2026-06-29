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


std::vector<studentas> readStudentaiFromFile(const std::string &filename)
{
    std::vector<studentas> studentai;
    std::ifstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Nepavyko atidaryti failo: " + filename);

    std::string line;

    auto start = std::chrono::high_resolution_clock::now();

    if (!std::getline(file, line))
        throw std::runtime_error("Failas tuščias arba sugadintas: " + filename);

    std::istringstream headerStream(line);
    std::string token;
    int ndCount = 0;
    while (headerStream >> token)
    {
        if (token.find("ND") != std::string::npos)
            ndCount++;
    }

    int lineNumber = 1;
    while (std::getline(file, line))
    {
        lineNumber++;
        if (line.empty()) continue;

        std::istringstream ss(line);
        studentas s;

        if (!(ss >> s.vardas >> s.pavarde))
            throw std::runtime_error("Eilutėje " + std::to_string(lineNumber) + " trūksta vardo arba pavardės.");

        for (int i = 0; i < ndCount; i++)
        {
            int nd;
            if (!(ss >> nd))
                throw std::runtime_error("Eilutėje " + std::to_string(lineNumber) + " trūksta namų darbo pažymio.");
            if (nd < minPazymys || nd > maxPazymys)
                throw std::runtime_error("Eilutėje " + std::to_string(lineNumber) + " pažymys už ribų (" + std::to_string(minPazymys) + "-" + std::to_string(maxPazymys) + "): " + std::to_string(nd));
            s.namuDarbai.push_back(nd);
        }

        if (!(ss >> s.egzaminas))
            throw std::runtime_error("Eilutėje " + std::to_string(lineNumber) + " trūksta egzamino pažymio.");
        if (s.egzaminas < minPazymys || s.egzaminas > maxPazymys)
            throw std::runtime_error("Eilutėje " + std::to_string(lineNumber) + " egzamino pažymys už ribų (" + std::to_string(minPazymys) + "-" + std::to_string(maxPazymys) + "): " + std::to_string(s.egzaminas));

        studentai.push_back(s);
    }
    file.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Studentų nuskaitymas užtruko: " << elapsed.count() << " sekundžių.\n";
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
