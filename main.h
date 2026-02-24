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

struct studentas 
{
    std::string vardas {};
    std::string pavarde {};
    std::vector<int> namuDarbai;
    int egzaminas {};
    double galutinis {};
};

struct studentasNode {
    studentas data;
    studentasNode* next;
};

void printWelcome();
void printNameAsk();
studentas* enterStudentaiArray(int* nPtr);
studentas enterStudentas(int n);
std::string enterName(int n);
std::string enterSurname(int n);
int enterNumberOfPazymys(int n);
std::vector<int> enterPazymiai(int n, int m);
int enterEgzaminas(int n);
bool isAllLetters(const std::string &input);
char askAverageOrMedian();
void calculateGalutinisArray(char choice, studentas* studentai, int n, double namuDarbaiSvertis, double egzaminasSvertis);
double calculateGalutinisMedian(const studentas &s, double namuDarbaiSvertis, double egzaminasSvertis);
double calculateGalutinisAverage(const studentas &s, double namuDarbaiSvertis, double egzaminasSvertis);
void printStudentaiArray(studentas* studentai, int n, char choice);

#endif
