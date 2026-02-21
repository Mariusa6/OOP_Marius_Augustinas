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

studentasNode* enterStudentai() {
    studentasNode* head{nullptr};
    studentasNode* tail{nullptr};
    char choice;
    int n{0};

    do
    {
        n++;
        studentasNode* newNode = new studentasNode();
        newNode->data = enterStudentas(n);
        newNode->next = nullptr;

        if (head == nullptr)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        std::cout << "Ar norite pridėti dar vieną studentą? (t/n): ";
        do
        {
            std::cin >> choice;
            choice = tolower(choice);
            if (choice != 't' && choice != 'n')
                std::cout << "Netinkama įvestis, bandykite 't' arba 'n': ";
        } while (choice != 't' && choice != 'n');

    } while (choice == 't');

    return head;
}

studentas enterStudentas(int n)
{
    studentas ivedamas;
    std::cout << '#' << n << " studentas:\n";
    ivedamas.vardas = enterName(n);
    ivedamas.pavarde = enterSurname(n);
    ivedamas.namuDarbai = enterPazymiai(n, enterNumberOfPazymys(n));
    ivedamas.galutinis = enterEgzaminas(n);
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

int main()
{
    setlocale(LC_ALL, "Lithuanian");
    printWelcome();
    printNameAsk();
    studentasNode* studentai = enterStudentai();
    return 0;
}
