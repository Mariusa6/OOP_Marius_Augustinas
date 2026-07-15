#ifndef FILE_H_DEFINED
#define FILE_H_DEFINED

#include "main.h"
#include <iostream> // cout, cin
#include <fstream>  // ifstream, ofstream
#include <sstream>  // istringstream
#include <vector>   // vector
#include <string>   // string
#include <chrono>   // high_resolution_clock
#include <iomanip>  // setprecision, setw

// -------------------------------------------------------
// Pagalbinė funkcija: nuskaito vieną studentas iš eilutės.
// Naudojama šablone readStudentaiFromFile<Container>.
// -------------------------------------------------------
inline studentas parseStudentasLine(const std::string &line,
                                    int ndCount,
                                    int lineNumber)
{
    std::istringstream ss(line);
    studentas s;
 
    if (!(ss >> s.vardas >> s.pavarde))
        throw std::runtime_error("Eilutėje " + std::to_string(lineNumber)
                                 + " trūksta vardo arba pavardės.");
 
    for (int i = 0; i < ndCount; i++)
    {
        int nd;
        if (!(ss >> nd))
            throw std::runtime_error("Eilutėje " + std::to_string(lineNumber)
                                     + " trūksta namų darbo pažymio.");
        if (nd < minPazymys || nd > maxPazymys)
            throw std::runtime_error("Eilutėje " + std::to_string(lineNumber)
                                     + " pažymys už ribų ("
                                     + std::to_string(minPazymys) + "-"
                                     + std::to_string(maxPazymys) + "): "
                                     + std::to_string(nd));
        s.namuDarbai.push_back(nd);
    }
 
    if (!(ss >> s.egzaminas))
        throw std::runtime_error("Eilutėje " + std::to_string(lineNumber)
                                 + " trūksta egzamino pažymio.");
    if (s.egzaminas < minPazymys || s.egzaminas > maxPazymys)
        throw std::runtime_error("Eilutėje " + std::to_string(lineNumber)
                                 + " egzamino pažymys už ribų ("
                                 + std::to_string(minPazymys) + "-"
                                 + std::to_string(maxPazymys) + "): "
                                 + std::to_string(s.egzaminas));
    return s;
}
 
// -------------------------------------------------------
// Template: readStudentaiFromFile<Container>
// Nuskaito studentus iš .txt failo į bet kokį konteinerį
// (vector, list, deque) naudojant push_back.
// Failo formatas: antraštė su ND1..NDn ir Egzaminas stulpeliais.
// -------------------------------------------------------
template<typename Container>
Container readStudentaiFromFile(const std::string &filename)
{
    Container studentai;
    std::ifstream file(filename);
 
    if (!file.is_open())
        throw std::runtime_error("Nepavyko atidaryti failo: " + filename);
 
    std::string line;
 
    if (!std::getline(file, line))
        throw std::runtime_error("Failas tuščias arba sugadintas: " + filename);
 
    // Apskaičiuojame ND stulpelių skaičių iš antraštės
    std::istringstream headerStream(line);
    std::string token;
    int ndCount = 0;
    while (headerStream >> token)
        if (token.find("ND") != std::string::npos) ndCount++;
 
    int lineNumber = 1;
    while (std::getline(file, line))
    {
        lineNumber++;
        if (line.empty()) continue;
        studentai.push_back(parseStudentasLine(line, ndCount, lineNumber));
    }
 
    return studentai;
}

#endif // FILE_H_DEFINED
