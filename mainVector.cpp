#include "main.h"

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    printWelcome();
    int n {};
    char choice {};
    char sortChoice {};
    std::vector<studentas> studentaiVector {};
    choice = askMenuChoice();
    std::string inputFileName {};
    std::string outputFileName {};
    switch (choice)
    {
        case '1':
            studentaiVector = enterStudentaiVector();
            calculateGalutinisVector(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
            printStudentaiVector(studentaiVector);
            break;
        case '2':
            n = enterNumberOfStudents();
            studentaiVector = generateOnlyPazymiai(n);
            calculateGalutinisVector(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
            printStudentaiVector(studentaiVector);
            break;
        case '3':
            n = enterNumberOfStudents();
            studentaiVector = generateStudentai(n);
            calculateGalutinisVector(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
            sortChoice = askSortBy();
            sortStudentai(studentaiVector, sortChoice);
            printStudentaiVector(studentaiVector);
            break;
        case '4':
            inputFileName = enterFileName();
            studentaiVector = readStudentaiFromFile(inputFileName);
            calculateGalutinisVector(studentaiVector, namuDarbaiSvertis, egzaminasSvertis);
            sortChoice = askSortBy();
            sortStudentai(studentaiVector, sortChoice);
            outputFileName = enterOutputFileName();
            writeStudentaiToFile(studentaiVector, outputFileName);
            break;
        case '5':
            std::cout << "Programa baigta.\n";
            break;
    }
    return 0;
}

std::vector<studentas> enterStudentaiVector() {
    std::vector<studentas> tmp;
    int n{1};
    do
    {
        tmp.push_back(enterStudentas(n));
        n++;
    } while (askIfMoreStudents());
    
    return tmp;
}

bool askIfMoreStudents()
{
    char choice;
    std::cout << "Ar norite įvesti dar vieną studentą? (y/n): ";
    do 
    {
        std::cin >> choice;
        choice = tolower(choice);
        if (choice != 'y' && choice != 'n')
            std::cout << "Netinkama įvestis, bandykite 'y' arba 'n': ";
    } while (choice != 'y' && choice != 'n');
    return choice == 'y';
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

void calculateGalutinisVector(std::vector<studentas> &studentai, double namuDarbaiSvertis, double egzaminasSvertis)
{
    for(int i = 0; i < studentai.size(); i++)
    {
        studentai[i].galutinisVid = calculateGalutinisAverage(studentai[i], namuDarbaiSvertis, egzaminasSvertis);
        studentai[i].galutinisMed = calculateGalutinisMedian(studentai[i], namuDarbaiSvertis, egzaminasSvertis);
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

char askSortBy()
{
    char choice;
    std::cout << "Rikiavimas pagal:\n"
    << "1. Vardą\n"
    << "2. Pavardę\n"
    << "3. Galutinį įvertinimą pagal vidurkį\n"
    << "4. Galutinį įvertinimą pagal medianą\n"
    << "Jūsų pasirinkimas: ";
     do
     {
         std::cin >> choice;
         if (choice < '1' || choice > '4')
             std::cout << "Netinkama įvestis, bandykite dar kartą: ";
     } while (choice < '1' || choice > '4');
     return choice;
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

void printStudentaiVector(const std::vector<studentas> &studentai)
{
    std::cout << std::left << std::setw(20) << "Vardas"
        << std::left << std::setw(20) << "Pavardė"
        << std::left << std::setw(20) << "Galutinis (Vid.)"
        << std::left << std::setw(20) << "Galutinis (Med.)\n";
    std::cout << "-----------------------------------------------------------------------\n";
    for(int i = 0; i < studentai.size(); i++)
    {
        std::cout << std::left << std::setw(20) << studentai[i].vardas
            << std::left << std::setw(20) << studentai[i].pavarde
            << std::left << std::setw(20) << std::fixed << std::setprecision(2) << studentai[i].galutinisVid
            << std::left << std::setw(20) << studentai[i].galutinisMed << "\n";
    }
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
