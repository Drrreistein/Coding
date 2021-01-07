#pragma once
#include <map>
#include <unordered_map>
#include <iostream>
#include "add_header.h"

using namespace std;

// Display set
template <class T>
void DisplaySet(const std::set<T>& s){
    std::cout << "Set: [";
    for (auto& vi : s)
    {
        std::cout << vi << ", ";
    }
    std::cout << "]" << std::endl;
}
template <class T>
void DisplaySet(const std::set<T>& s, string str){
    std::cout << str << ": [";
    for (auto& vi : s)
    {
        std::cout << vi << ", ";
    }
    std::cout << "]" << std::endl;
}

// Display vector
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
template <class T>
void DisplayVector(const std::vector<T>& vec, string str)
{
    std::cout << str << ": [";
    for (auto& vi : vec)
    {
        std::cout << vi << ", ";
    }
    std::cout << "]" << std::endl;
}

// Displace matrix
template <class T>
void DisplayMatrix(const std::vector<std::vector<T>>& mat)
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
template <class T>
void DisplayMatrix(const std::vector<std::vector<T>>& mat, string str)
{
    std::cout << str << ": [" << std::endl;
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

// Display Map and unordered_map
template <class T, class S>
void DisplayMap(const unordered_map<T, S>& ma) {
    // display uordered_map
    std::cout << "UMap: [" << std::endl;
    for (auto it = ma.begin(); it!=ma.end(); ++it) {
        cout << it->first << ": " << it->second << " ; ";
    }
    cout << endl;
}
template <class T, class S>
void DisplayMap(const map<T, S>& ma) {
    // display map
    std::cout << "Map: [" << std::endl;
    for (auto it = ma.begin(); it != ma.end(); ++it) {
        cout << it->first << ": " << it->second << " ; ";
    }
    cout << endl;
}
template <class T, class S>
void DisplayMap(const unordered_map<T, S>& ma, string str) {
    // display uordered_map
    std::cout << str << ": [" << std::endl;
    for (auto it = ma.begin(); it!=ma.end(); ++it) {
        cout << it->first << ": " << it->second << " ; ";
    }
    cout << endl;
}
template <class T, class S>
void DisplayMap(const map<T, S>& ma, string str) {

    // display map
    std::cout << str << ": [" << std::endl;
    for (auto it = ma.begin(); it != ma.end(); ++it) {
        cout << it->first << ": " << it->second << " ; ";
    }
    cout << endl;
}

// display queue
template <class T>
void DisplayQueue(const std::queue<T>& s){
    std::cout << "Queue: [";
    queue<T> tmp=s;
    while(!tmp.empty())
    {
        std::cout << tmp.front() << ", ";
        tmp.pop();
    }
    std::cout << "]" << std::endl;
}
template <class T>
void DisplayQueue(const std::queue<T>& s, string str){
    std::cout << str << ": [";
    queue<T> tmp=s;
    while(!tmp.empty())
    {
        std::cout << tmp.front() << ", ";
        tmp.pop();
    }
    std::cout << "]" << std::endl;
}

// display deque


// display List
template <class T>
void DisplayList(const std::list<T>& t){
    std::cout << "List: [";
    for (auto& x : t)
        std::cout << x << ", ";
    std::cout << "]" << std::endl;
}
template <class T>
void DisplayList(const std::list<T>& t, string str){
    std::cout << str << ": [";
    for (auto& x : t)
        std::cout << x << ", ";
    std::cout << "]" << std::endl;
}

// display Array


// display Stack
template <class T>
void DisplayStack(const std::stack<T>& st){
    std::cout << "Stack: [" ;
    stack<T> tmp=st;
    while(!tmp.empty()){
        std::cout << tmp.top() << ", "; 
        tmp.pop();
    }
    std::cout << "]" << std::endl;
}
template <class T>
void DisplayStack(const std::stack<T>& st, string str){
    std::cout << str << ": [" ;
    stack<T> tmp=st;
    while(!tmp.empty()){
        std::cout << tmp.top() << ", "; 
        tmp.pop();
    }
    std::cout << "]" << std::endl;
}