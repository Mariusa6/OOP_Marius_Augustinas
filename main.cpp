#include "main.h"

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

studentas enterStudentas(int n)
{
    studentas ivedamas;
    std::cout << '#' << n << " studentas:\n";
    ivedamas.vardas = enterName(n);
    ivedamas.pavarde = enterSurname(n);



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

bool isAllLetters(const std::string &input) {
    return std::all_of(input.begin(), input.end(), ::isalpha);
}

int main()
{
    setlocale(LC_ALL, "Lithuanian");
    printWelcome();
    printNameAsk();

    return 0;
}
