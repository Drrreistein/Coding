#pragma once
using namespace std;
#include <stack>
#include <string>
#include <algorithm> // use max()

class BackspaceCompare {
public:
    bool solu1(string S, string T) {
        bool res = true;
        while (S != "" && T !="") {
            if (S[0] != T[0]) {

            }
            else {
                S = &S[1];
                T = &T[1];

            }
        }
        if (S != "" || T != "") {
            res = false;
        }
        return res;
    }

    bool solu2(string S, string T) {
        /**
        methods: find individual pureWord of S and T, compare if they are equal.
        pureWord(): use a stack based approach, realization with variable type of string

        time: O(M+N), M and N are the lengths of S and T
        space: O(M+N)
        */
        string s1 = pureWord(S);
        string t1 = pureWord(T);
        cout << "s1: "<<s1 << ", t1: "<<t1 << endl;
        if (s1 != t1) { return false; }
        return true;
    }
    string pureWord(string str) {
        string res="";
        for (size_t i = 0; i < str.size(); i++)
        {
            if (str[i] != '#') { // when '#' not appears
                res.append(1,str[i]); // append char 
            }
            else if (res != "") { // when '#' appears and res not empty 
                res.erase(res.end()-1); // erase the last char of res
            }
        }
        return res;
    }

    bool solu3(string S, string T) {
        /**
        methods: find individual pureWord of S and T, compare if they are equal.
        pureWord2(): use a stack based approach, realization using variable type of stack

        time: O(M+N), M and N are the lengths of S and T
        space: O(M+N)
        */
        stack<char> s1 = pureWord2(S);
        stack<char> t1 = pureWord2(T);
        //cout << "s1: " << s1 << ", t1: " << t1 << endl;
        if (s1 != t1) { return false; }
        return true;
    }
    stack<char> pureWord2(string str) {
        stack<char> res;
        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] != '#') {
                res.push(str[i]);
            }
            else if (!res.empty()) {
                res.pop();
            }
        }
        return res;
    }

    bool solu4(string S,string T) {
        /**
        methods: two pointers, one to traverse the string, one to store the position of character.

        time: O(M+N)
        space: O(1)
        */
        int s=0,t=0;
        for (size_t i = 0; i < S.length(); i++)
        {
            if (S[i] == '#') {
                s--;
                s = max(0, s);
            }
            else {
                S[s] = S[i];
                s++;
            }
        }
        for (size_t i = 0; i < T.length(); i++)
        {
            if (T[i] == '#') {
                t--;
                t = max(0, t);
            }
            else {
                T[t] = T[i];
                t++;
            }
        }
        //cout << " S " << S << " s "<< s <<  " T " << T<< " t " << t << endl;
        if (s != t) {
            return false;
        }
        else {
            for (size_t i = 0; i < s; i++)
            {
                if (S[i] != T[i]) {
                    return false;
                }
            }
            return true;
        }
    }

    bool solu5(string S, string T) {
        /*
        method, two pointers, traverse the string reverse

        time: O(M+N)
        space O(1)
        */
        int s = S.length()-1, t = T.length()-1;
        int k = 0;
        for (int i = s; i >=0; i--)
        {
            if (S[i] == '#') {
                k++;
            }
            else if (k > 0) {
                k--;
            }
            else if (k == 0) {
                S[s] = S[i];
                s--;
            }
        }
        k = 0;
        for (int i = t; i >= 0; i--)
        {
            if (T[i] == '#') {
                k++;
            }
            else if (k > 0) {
                k--;
            }
            else if (k == 0) {
                T[t] = T[i];
                t--;
            }
        }
        cout << " S " << S << " s "<< s <<  " T " << T<< " t " << t << endl;
        if (t != s) {
            return false;
        }
        else {
            for (size_t i = s+1; i < S.length(); i++)
            {
                if (S[i] != T[i]) {
                    return false;
                }
            }
            return true;
        }
        
    }
};