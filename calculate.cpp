#include "calculate.h"

void calculateGalutinisVector(std::vector<studentas> &studentai, double namuDarbaiSvertis, double egzaminasSvertis)
{
    if (studentai.empty())
        throw std::runtime_error("Studentų sąrašas tuščias — nėra ką skaičiuoti.");

    for(auto &s : studentai)
    {
        s.galutinisVid = calculateGalutinisAverage(s, namuDarbaiSvertis, egzaminasSvertis);
        s.galutinisMed = calculateGalutinisMedian(s, namuDarbaiSvertis, egzaminasSvertis);
    }
}

double calculateGalutinisAverage(const studentas &s, double namuDarbaiSvertis, double egzaminasSvertis) {
    double namuDarbaiVidurkis{0.0};
    if (!s.namuDarbai.empty())
    {
        namuDarbaiVidurkis = std::accumulate(s.namuDarbai.begin(), s.namuDarbai.end(), 0.0) / s.namuDarbai.size();
    }
    return namuDarbaiSvertis * namuDarbaiVidurkis + egzaminasSvertis * s.egzaminas;
}

double calculateGalutinisMedian(const studentas &s, double namuDarbaiSvertis, double egzaminasSvertis)
{
    double namuDarbaiMediana{0.0};
    if (!s.namuDarbai.empty())
    {
        std::vector<int> sortedNamaiDarbai = s.namuDarbai;
        std::sort(sortedNamaiDarbai.begin(), sortedNamaiDarbai.end());
        size_t mid {sortedNamaiDarbai.size() / 2};
        namuDarbaiMediana = (sortedNamaiDarbai.size() % 2 == 0) ? (sortedNamaiDarbai[mid - 1] + sortedNamaiDarbai[mid]) / 2.0 : sortedNamaiDarbai[mid];
    }
    return namuDarbaiSvertis * namuDarbaiMediana + egzaminasSvertis * s.egzaminas;
}

void sortStudentai(std::vector<studentas> &studentai, char sortBy)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(studentai.begin(), studentai.end(), [sortBy](const studentas &a, const studentas &b) {
        switch (sortBy)
        {
            case '1':
                return a.vardas < b.vardas;
            case '2':
                return a.pavarde < b.pavarde;
            case '3':
                return a.galutinisVid > b.galutinisVid;
            case '4':
                return a.galutinisMed > b.galutinisMed;
            default:
                return false;
        }
    });
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Rikiavimas užtruko: " << elapsed.count() << " sekundžių.\n";
}
