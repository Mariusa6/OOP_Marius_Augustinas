#include "main.h"

void printWelcome();
void printNameAsk();
studentasNode* enterStudentai();
studentas enterStudentas(int n);
std::string enterName(int n);
std::string enterSurname(int n);
int enterNumberOfPazymys(int n);
std::vector<int> enterPazymiai(int n, int m);
int enterEgzaminas(int n);
bool isAllLetters(const std::string &input);
char askAverageOrMedian();
void calculateGalutinis(char choice, studentasNode* head, double namuDarbaiSvertis, double egzaminasSvertis);
double calculateGalutinisMedian(const studentas &s, double namuDarbaiSvertis, double egzaminasSvertis);
double calculateGalutinisAverage(const studentas &s, double namuDarbaiSvertis, double egzaminasSvertis);
void printStudentai(studentasNode* head, char choice);

int main()
{
    double namuDarbaiSvertis{0.4};
    double egzaminasSvertis{0.6};
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    printWelcome();
    printNameAsk();
    studentasNode* studentai = enterStudentai();
    char choice = askAverageOrMedian();
    calculateGalutinis(choice, studentai, namuDarbaiSvertis, egzaminasSvertis);
    printStudentai(studentai, choice);
    
    return 0;
}

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

void calculateGalutinis(char choice, studentasNode* head, double namuDarbaiSvertis, double egzaminasSvertis)
{
    studentasNode* current = head;
    while (current != nullptr)
    {
        if (choice == 'v')
            current->data.galutinis = calculateGalutinisAverage(current->data, namuDarbaiSvertis, egzaminasSvertis);
        else
            current->data.galutinis = calculateGalutinisMedian(current->data, namuDarbaiSvertis, egzaminasSvertis);
        current = current->next;
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

void printStudentai(studentasNode* head, char choice)
{
    studentasNode* current = head;
    std::cout << std::left << std::setw(15) << "Vardas"
        << std::left << std::setw(15) << "Pavarde"
        << std::left << std::setw(11) << "Galutinis (" << (choice == 'v' ? "Vid.)" : "Med.)") << "\n";
    std::cout << "---------------------------------------------\n";
    while (current != nullptr)
    {
        std::cout << std::left << std::setw(15) << current->data.vardas
            << std::left << std::setw(15) << current->data.pavarde
            << std::left << std::setw(20) << std::fixed << std::setprecision(2) << current->data.galutinis << "\n";
        current = current->next;
    }
}
