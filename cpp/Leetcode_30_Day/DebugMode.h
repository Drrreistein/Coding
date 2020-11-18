#pragma once
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

// Displace vector
template <class T>
void DisplayVector(const std::vector<T>& vec)
{
    std::cout << "Vector: [";
    for (auto& vi : vec)
    {
        std::cout << vi << ", ";
    }
    std::cout << "]" << std::endl;
}

// Displace matrix
void DisplayMatrix(const std::vector<std::vector<double>>& mat)
{
    std::cout << "Matrix: [" << std::endl;

    for (auto& vec : mat)
    {
        for (auto& vi : vec)
        {
            std::cout << vi << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "]" << std::endl;
}
void DisplayMatrix(const std::vector<std::vector<string>>& mat)
{
    std::cout << "Matrix: [" << std::endl;

    for (auto& vec : mat)
    {
        for (auto& vi : vec)
        {
            std::cout << vi << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "]" << std::endl;
}

void DisplayMap(const unordered_map<int, int>& ma) {
    // display map
    for (auto it = ma.begin(); it!=ma.end(); ++it) {
        cout << it->first << ": " << it->second << " ; ";
    }
    cout << endl;
}