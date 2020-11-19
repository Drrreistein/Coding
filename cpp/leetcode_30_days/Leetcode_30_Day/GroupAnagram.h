#pragma once
#include <unordered_map>
#include <map>
#include <vector>
#include <array>
using namespace std;


bool isAnagram(string str1, string str2);

class GroupAnagram {
public:
    vector<vector<string>> solu1(vector<string>& strs) {
        /*
        
        time: o(N2*M2), N is length of string vector, M is maximal length of string
        space: o(N*M)
        */
        vector<vector<string>> res;
        int length = strs.size();
        vector<int> chos(length, 0);
        int r = 0;
        for (size_t i = 0; i < length; i++)
        {
            //DisplayVector(chos);
            if (chos[i] == 0) { // hasn't be choosed
                r++;
                vector<string> str_tmp;
                for (size_t j = i; j < length; j++)
                {
                    if (chos[j] == 0 && isAnagram(strs[i], strs[j])) {
                        str_tmp.push_back(strs[j]);
                        chos[j] = 1;
                    }
                }
                res.push_back(str_tmp);
            }
        }
        return res;
    }

    vector<vector<string>> solu2(vector<string>& strs) {
        /*
        method: hash map, using sorted string as key

        time: O(N * MlogM + N)
        space: O(N)
        */
        unordered_map<string, vector<string>> mapping;
        vector<vector<string>> res;
        // build the map
        for (auto x : strs) {
            string tmp = x;
            sort(tmp.begin(), tmp.end()); // http://www.cplusplus.com/reference/algorithm/sort/
            mapping[tmp].push_back(x);
        }
        // operate output string matrix
        for (auto x : mapping) {
            res.push_back(x.second);
        }
        return res;
    }

    vector<vector<string>> solu3(vector<string>& strs) {
        /*
        method: hash map, using counter array as key(count of all 26 digits), string counter as the hashmap key
        not implemented!!

        time: O(N * M)
        space: O(N*M)
        */
        //unordered_map<vector<int>, vector<string>> mapping;
        unordered_map<string, vector<string>> mapping;
        vector<vector<string>> res;

        // build map
        for (auto x : strs) {
            //vector<int> counter(26, 0);
            string counter = "00000000000000000000000000";
            for (char c : x) {
                counter[c - 'a']++;
            }
            mapping[counter].push_back(x);
        }

        // opearte output string matrix
        for (auto x : mapping) {
            res.push_back(x.second);
        }

        return res;
    }

    vector<vector<string>> solu4(vector<string>& strs) {
        /*
        method: hash map, using counter array as key(count of all 26 digits), int array as hashmap key
        not implemented!!

        time: O(N * M)
        space: O(N * M)
        */
        
        typedef array<int, 26> alphabet;
        map<alphabet, vector<string>> mapping; // unordered_map not suitable here
        vector<vector<string>> res;

        // build map
        for (auto x : strs) {
            //vector<int> counter(26, 0);
            alphabet counter = {0};
            for (char ch : x) {
                counter[ch - 'a']++;
            }
            mapping[counter].push_back(x);
        }

        // opearte output string matrix
        for (auto x : mapping) {
            res.push_back(x.second);
        }

        return res;
    }

    vector<vector<string>> solu5(vector<string>& strs) {
        /*
        method: hash map, using unique hash code of each string as key
        but not suitable for too big string

        time:
        space:
        */
        unordered_map<uint64_t, vector<string>> mapping;
        vector<vector<string>> res;
        int hashCode[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };

        // build map
        for (auto x : strs) {
            uint64_t num = 1;
            for (char ch : x) {
                num *= hashCode[ch - 'a'];
            }
            mapping[num].push_back(x);
        }
        // extract string matrix
        for (auto m : mapping) {
            res.push_back(m.second);
        }

        return res;
    }

};

bool isAnagram(string str1, string str2) {
    if (str1.size() != str2.size()) {
        return false;
    }

    int length = str1.size();
    for (size_t i = 0; i < length; i++)
    {
        int ind = str2.find(str1[i]);
        if (ind >= 0) { char tmp = str2[i]; str2[i] = str2[ind]; str2[ind] = tmp; }
        else { return false; }
    }

    if (str1 == str2) {
        return true;
    }
    return false;
}