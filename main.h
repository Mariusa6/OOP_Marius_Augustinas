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

#endif
