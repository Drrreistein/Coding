// LeetCode_30_Day_Week_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "SubarraySum.h"
#include "CanJump.h"
#include "LRUCache.h"
#include "LongestCommonSubsequence.h"
#include "MaximalSquare.h"
#include "MaxPathSum.h"
#include "RangeBitwiseAnd.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    cout << "\n ################################### q1: Subarray Sum Equals K ################################## " << endl;
    vector<int> nums = { -1,-1,1 };
    int k = 0;
    SubarraySum q1;
    cout << "number of subarrays: " << q1.solu1(nums, k) << endl;
    cout << "number of subarrays: " << q1.solu2(nums, k) << endl;

    cout << "\n ################################### q2: Bitwise AND of Numbers Range ################################## " << endl;
    int m = 5, n = 7;
    RangeBitwiseAnd q2;
    cout << "bitwise AND of " << m << " and " << n << " is: " << q2.solu1(m, n) << endl;
    cout << "bitwise AND of " << m << " and " << n << " is: " << q2.solu2(m, n) << endl;
    unsigned int a = 5, b = 7;
    printf("a&b = %d\n", a & b);

    cout << "\n ################################### q3: Least Recently Used Cache ################################## " << endl;
    LRUCache q3(2);
    q3.put(1, 1);
    q3.put(2, 2);
    cout << q3.get(1) << endl;
    q3.put(3, 3);
    cout << q3.get(2) << endl;
    q3.put(4, 4);
    cout << q3.get(1) << endl;
    cout << q3.get(3) << endl;
    cout << q3.get(4) << endl;

    cout << "\n ################################### q4: Jump Game ################################## " << endl;
    vector<int> nums_q4 = {2, 3, 1, 0, 4};
    //nums_q4 = { 2,0};
    CanJump q4;
    cout << "can jump:" << q4.solu1(nums_q4) << endl;
    cout << "can jump:" << q4.solu2(nums_q4) << endl;

    cout << "\n ################################### q5: longest Common Subsequence ################################## " << endl;
    string text1="abcde";
    string text2="ace";
    LongestCommonSubsequence q5;
    cout << "longest Common Subsequence: " << q5.solu1(text1, text2) << endl;
    cout << "longest Common Subsequence: " << q5.solu2(text1, text2) << endl;

    cout << "\n ################################### q6: maximal square ################################## " << endl;
    vector<vector<int>> mat={{1, 0, 1, 0, 0}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1},{1, 0, 0, 1, 0}};
    mat={{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {0,0,0,0,0}, {1, 1, 1, 1, 1},{1, 1, 1, 1, 1}};
    MaximalSquare q6;
    DisplayMatrix(mat);
    cout << "maximal square: " << q6.solu1(mat) << endl;
    cout << "maximal square: " << q6.solu2(mat) << endl;
    
}
