#pragma once
/*
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.



If there is no common subsequence, return 0.



Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/
#include <vector>
using namespace std;
#include "DebugMode.h"

class LongestCommonSubsequence {
public:
    int solu1(string text1, string text2){
        /**
         * methods: dp
         * 
         * time: O(mn)
         * space: O(mn)
        */
        int m = text1.size();
        int n = text2.size();
        vector<vector<short>> ans(m + 1, vector<short>(n + 1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(text1[i]==text2[j]){
                    ans[i+1][j+1]=ans[i][j]+1;
                }else{
                    ans[i+1][j+1]=max(ans[i+1][j], ans[i][j+1]);
                }
            }
        }
        // DisplayMatrix(ans);
        return ans[m][n];
    }

    int solu2(string text1, string text2){
        int m = text1.size();
        int n = text2.size();
        if(m<n){return solu2(text2, text1);}
        vector<vector<short>> ans(2, vector<short>(n + 1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(text1[i]==text2[j]){
                    ans[(i+1)%2][j+1] = ans[i%2][j]+1;
                }else{
                    ans[(i+1)%2][j+1] = max(ans[(i+1)%2][j], ans[i%2][j+1]);
                }
            }
        }
        //DisplayMatrix(ans);
        return ans[m%2][n];
    }
};