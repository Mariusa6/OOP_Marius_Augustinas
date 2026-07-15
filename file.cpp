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
