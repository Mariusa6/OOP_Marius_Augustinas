#include "main.h"

char askMenuChoice()
{
    char choice;
    std::cout << "Pasirikite veiksmą:\n";
    std::cout << "1. Įvesti studentus ranka\n";
    std::cout << "2. Generuoti tik pažymius\n";
    std::cout << "3. Generuoti studentų vardus ir pažymius\n";
    std::cout << "4. Baigti darbą\n";
    std::cout << "Jūsų pasirinkimas: ";
    do
    {
        std::cin >> choice;
        if (choice < '1' || choice > '4')
            std::cout << "Netinkama įvestis, bandykite dar kartą: ";
    } while (choice < '1' || choice > '4');
    return choice;
}
