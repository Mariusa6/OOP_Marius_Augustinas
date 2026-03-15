#include "menu.h"

char askMenuChoice()
{
    char choice;
    std::cout << "Pasirikite veiksmą:\n";
    std::cout << "1. Įvesti studentus ranka\n";
    std::cout << "2. Generuoti tik pažymius\n";
    std::cout << "3. Generuoti studentų vardus ir pažymius\n";
    std::cout << "4. Nuskaityti studentus iš failo\n";
    std::cout << "5. Baigti darbą\n";
    std::cout << "Jūsų pasirinkimas: ";
    do
    {
        std::cin >> choice;
        if (choice < '1' || choice > '5')
            std::cout << "Netinkama įvestis, bandykite dar kartą: ";
    } while (choice < '1' || choice > '5');
    return choice;
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
