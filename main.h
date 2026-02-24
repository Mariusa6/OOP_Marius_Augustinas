#ifndef MAIN_H
#define MAIN_H

#include <iostream>     // cout, cin
#include <string>       // string
#include <string_view>  // string_view
#include <vector>       // vector
#include <limits>       // numeric_limits
#include <ios>          // streamsize
#include <algorithm>    // all_of
#include <cctype>       // isalpha
#include <numeric>      // accumulate
#include <iomanip>      // setprecision, setw
#include <windows.h>    // SetConsoleOutputCP, SetConsoleCP
#include <random>      // mt19937, random_device

struct studentas 
{
    std::string vardas {};
    std::string pavarde {};
    std::vector<int> namuDarbai;
    int egzaminas {};
    double galutinis {};
};

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
std::vector<studentas> generateOnlyPazymiai(int n);
std::string generateStudentName();
std::string generateStudentSurname();
int generateNumberOfPazymys();
std::vector<int> generatePazymiai(int m);
int generatePazymys();

// Print functions
void printWelcome();
void printNameAsk();
void printStudentaiArray(studentas* studentai, int n, char choice);
void printStudentaiVector(const std::vector<studentas> &studentai, char choice);

// User input functions
int enterNumberOfStudents();
studentas* enterStudentaiArray(int n);
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

// Calculation functions
void calculateGalutinisArray(char choice, studentas* studentai, int n, double namuDarbaiSvertis, double egzaminasSvertis);
void calculateGalutinisVector(char choice, std::vector<studentas> &studentai, double namuDarbaiSvertis, double egzaminasSvertis);
double calculateGalutinisMedian(const studentas &s, double namuDarbaiSvertis, double egzaminasSvertis);
double calculateGalutinisAverage(const studentas &s, double namuDarbaiSvertis, double egzaminasSvertis);

// Utility functions
bool isAllLetters(const std::string &input);

#endif
