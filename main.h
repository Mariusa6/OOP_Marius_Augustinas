#ifndef MAIN.H
#define MAIN.H

#include <iostream>     // cout, cin
#include <string>       // string
#include <string_view>  // string_view
#include <vector>       // vector
#include <limits>       // numeric_limits
#include <ios>          // streamsize
#include <algorithm>    // all_of
#include <cctype>       // isalpha

struct studentas 
{
    std::string vardas {};
    std::string pavarde {};
    std::vector<int> namuDarbai;
    int egzaminas {};
    int galutinis {};
};

#endif
