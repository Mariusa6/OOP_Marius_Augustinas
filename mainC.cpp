#include "main.h"

int main()
{
    double namuDarbaiSvertis{0.4};
    double egzaminasSvertis{0.6};
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    printWelcome();
    printNameAsk();
    int n{};
    n = enterNumberOfStudents();
    studentas* studentai = enterStudentaiArray(n);
    char choice = askAverageOrMedian();
    calculateGalutinisArray(choice, studentai, n, namuDarbaiSvertis, egzaminasSvertis);
    printStudentaiArray(studentai, n, choice);
    
    delete[] studentai;
    return 0;
}

int enterNumberOfStudents()
{
    int n;
    std::cout << "Įveskite studentų skaičių: ";
    while (!(std::cin >> n) || n <= 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Iveskite teigiamą skaičių.\n";
        std::cout << "Įveskite studentų skaičių: ";
    }
    return n;
}

studentas* enterStudentaiArray(int n) {
    studentas* studentai = new studentas[n];
    for (int i = 0; i < n; i++)
    {
        studentai[i] = enterStudentas(i + 1);
    }
    return studentai;
}

studentas enterStudentas(int n)
{
    studentas ivedamas;
    std::cout << '#' << n << " studentas:\n";
    ivedamas.vardas = enterName(n);
    ivedamas.pavarde = enterSurname(n);
    ivedamas.namuDarbai = enterPazymiai(n, enterNumberOfPazymys(n));
    ivedamas.egzaminas = enterEgzaminas(n);
    return ivedamas;
}

std::string enterName(int n)
{
    std::string v;

    std::cout << "Iveskite studento #" << n << " vardą: ";
    while (!(std::cin >> v) || !isAllLetters(v))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Naudokite raides. Iveskite studento varda: ";
    }
    
    return v;
}

std::string enterSurname(int n)
{
    std::string v;

    std::cout << "Iveskite studento #" << n << " pavardę: ";
    while (!(std::cin >> v) || !isAllLetters(v))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Naudokite raides.\n";
        std::cout << "Iveskite studento #" << n << " pavardę: ";
    }
    
    return v;
}

int enterNumberOfPazymys(int n)
{
    int tmp{};

    std::cout << "Iveskite kiek #" << n << " studentas turėjo namų darbų: ";
    while (!(std::cin >> tmp) || tmp < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Iveskite neneigiamą skaičių.\n";
        std::cout << "Iveskite kiek #" << n << " studentas turėjo namų darbų: ";
    }

    return tmp;
}

int enterPazymys(int n)
{
    int tmp {};

    std::cout << n << " pazymys: ";
    while (!(std::cin >> tmp) || tmp < 1 || tmp > 10)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Iveskite skaiciu nuo 1 iki 10.\n";
        std::cout << n << " pazymys: ";
    }

    return tmp;
}

std::vector<int> enterPazymiai(int n, int m) // n - studento numeris, m - pažymių skaičius
{
    std::vector<int> tmp;
    std::cout << "Iveskite #" << n << " studento namų darbų pažymius.\n";
    for(int i{0} ; i < m ; i++)
    {
        tmp.push_back(enterPazymys(i+1));
    }
    return tmp;
}

int enterEgzaminas(int n)
{
    int tmp{};

    std::cout << "Iveskite kiek #" << n << " studentas gavo iš egzamino.\n";
    while (!(std::cin >> tmp) || tmp < 1 || tmp > 10)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Iveskite skaiciu nuo 1 iki 10.\n";
        std::cout << "Iveskite kiek #" << n << " studentas gavo iš egzamino.\n";
    }

    return tmp;
}

bool isAllLetters(const std::string &input) {
    return std::all_of(input.begin(), input.end(), ::isalpha);
}

char askAverageOrMedian()
{
    char choice;
    std::cout << "Ar norite naudoti vidurkį (v) ar medianą (m) galutiniam įvertinimui apskaičiuoti? (v/m): ";
    do
    {
        std::cin >> choice;
        choice = tolower(choice);
        if (choice != 'v' && choice != 'm')
            std::cout << "Netinkama įvestis, bandykite 'v' arba 'm': ";
    } while (choice != 'v' && choice != 'm');
    return choice;
}

void calculateGalutinisArray(char choice, studentas* studentai, int n, double namuDarbaiSvertis, double egzaminasSvertis)
{
    for(int i = 0; i < n; i++)
    {
        if (choice == 'v')
            studentai[i].galutinis = calculateGalutinisAverage(studentai[i], namuDarbaiSvertis, egzaminasSvertis);
        else
            studentai[i].galutinis = calculateGalutinisMedian(studentai[i], namuDarbaiSvertis, egzaminasSvertis);
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

void printStudentaiArray(studentas* studentai, int n, char choice)
{
    std::cout << std::left << std::setw(15) << "Vardas"
        << std::left << std::setw(15) << "Pavardė"
        << std::left << std::setw(11) << "Galutinis (" << (choice == 'v' ? "Vid.)" : "Med.)") << "\n";
    std::cout << "---------------------------------------------\n";
    for(int i = 0; i < n; i++)
    {
        std::cout << std::left << std::setw(15) << studentai[i].vardas
            << std::left << std::setw(15) << studentai[i].pavarde
            << std::left << std::setw(11) << std::fixed << std::setprecision(2) << studentai[i].galutinis << "\n";
    }
}
