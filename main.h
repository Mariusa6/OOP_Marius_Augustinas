#ifndef MAIN_H_DEFINED
#define MAIN_H_DEFINED

#include <iostream>     // cout, cin
#include <string>       // string
#include <vector>       // vector
#include <windows.h>    // SetConsoleOutputCP, SetConsoleCP
#include <exception>     // exception

struct studentas 
{
    std::string vardas {};
    std::string pavarde {};
    std::vector<int> namuDarbai;
    int egzaminas {};
    double galutinisVid {};
    double galutinisMed {};
};

const int minPazymys{1};
const int maxPazymys{10};

const double namuDarbaiSvertis{0.4};
const double egzaminasSvertis{0.6};

const std::vector<std::string> lithuanianNames = {
  "Tomas", "Lukas", "Mantas", "Erikas", "Darius",
  "Mindaugas", "Vytautas", "Andrius", "Justas", "Rokas",
  "Aistė", "Rūta", "Indrė", "Gabija", "Eglė",
  "Dovilė", "Kristina", "Agnė", "Viktorija", "Jūratė"
};

const std::vector<std::string> lithuanianSurnames = {
  "Kazlauskas", "Petrauskas", "Jankauskas", "Paulauskas", "Stankevičius",
  "Žukauskas", "Butkus", "Vasiliauskas", "Mockus", "Grigas",
  "Kairytė", "Stonytė", "Norkutė", "Rimkutė", "Barkauskaitė",
  "Tamošiūnaitė", "Januševičiūtė", "Gedvilaitė", "Urbonaitė", "Mikalajūnaitė"
};

// Function declarations

// Menu functions
char askMenuChoice();

// Generate functions
std::vector<studentas> generateStudentai(int n);
studentas* generateStudentaiArray(int n);
std::vector<studentas> generateOnlyPazymiai(int n);
studentas* generateOnlyPazymiaiArray(int n);
std::string generateStudentName(int n);
std::string generateStudentSurname(int n);
int generateNumberOfPazymys();
std::vector<int> generatePazymiai(int m);

// Print functions
void printWelcome();
void printNameAsk();
void printStudentaiArray(studentas* studentai, int n, char choice);
void printStudentaiVector(const std::vector<studentas> &studentai);
void outputStudentai(const std::vector<studentas> &studentai, char choice);

// User input functions
int enterNumberOfStudents();
studentas* enterStudentaiArray(int &n);
std::vector<studentas> enterStudentaiVector();
bool askIfMoreStudents();
studentas enterStudentas(int n);
std::string enterName(int n);
std::string enterSurname(int n);
int enterNumberOfPazymys(int n);
int enterPazymys(int n);
std::vector<int> enterPazymiai(int n, int m);
int enterEgzaminas(int n);
char askAverageOrMedian();
char askSortBy();
char askOutputChoice();

// Calculation functions
void calculateGalutinisArray(char choice, studentas* studentai, int n, double namuDarbaiSvertis, double egzaminasSvertis);
void calculateGalutinisVector(std::vector<studentas> &studentai, double namuDarbaiSvertis, double egzaminasSvertis);
double calculateGalutinisMedian(const studentas &s, double namuDarbaiSvertis, double egzaminasSvertis);
double calculateGalutinisAverage(const studentas &s, double namuDarbaiSvertis, double egzaminasSvertis);

// File handling functions
std::string enterFileName();
std::vector<studentas> readStudentaiFromFile(const std::string &filename);
std::string enterOutputFileName();
void writeStudentaiToFile(const std::vector<studentas> &studentai, const std::string &filename);

// Sorting functions
void sortStudentai(std::vector<studentas> &studentai, char sortChoice);

// Utility functions
bool isAllLetters(const std::string &input);

#endif
