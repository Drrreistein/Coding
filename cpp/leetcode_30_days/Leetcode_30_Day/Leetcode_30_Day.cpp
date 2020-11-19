// Leetcode_30_Day.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "SingleNumber.h"
#include "HappyNumber.h"
#include "MaxSubArray.h"
#include "MoveZeroes.h"
#include "DebugMode.h"
#include "MaxProfit.h"
#include "GroupAnagram.h"

using namespace std;

int main()
{
    /*int car[5] = { 1,2,3,4,5 };
    int* p = &car[3];
    cout << p[0] << " , "<< p[1] << " , " << endl;*/
    //string str_counter = "00000000000000000000000000";
    //cout << str_counter.size() << endl;

    // question 6: group anagrams together
    vector<string> q6_str = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaa"};//{ "eat","tea","tan","ate","nat","bat" };
    GroupAnagram q6;
    DisplayVector(q6_str);
    DisplayMatrix(q6.solu1(q6_str)); // my own
    DisplayMatrix(q6.solu2(q6_str));
    DisplayMatrix(q6.solu3(q6_str));
    DisplayMatrix(q6.solu4(q6_str));
    DisplayMatrix(q6.solu5(q6_str));

    // question 5: best time to buy and sell stock II
    vector<int> q5_prices = {1,7,2,3,6,7,6,7};
    DisplayVector(q5_prices);
    MaxProfit q5;
    cout << "Total Profit - solu1: " << q5.solu1(q5_prices) << endl;
    cout << "Total Profit - solu2: " << q5.solu2(q5_prices) << endl;
    cout << "Total Profit - solu3: " << q5.solu3(q5_prices) << endl;

    // question 4: Move Zeroes
    cout << "\n ############### q4 ################" << endl;
    vector<int> nums_q4 = {0,1,0,3,12};
    MoveZeroes q4;
    DisplayVector(nums_q4);
    q4.solution4(nums_q4);
    DisplayVector(nums_q4);

    // question 3: Maximum Subarrays, no official answer
    cout << "\n ############### q3 ################" << endl;
    MaxSubArray q3;
    vector<int> nums_q3 = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    cout << "Sum of Maximum Subarray: " << q3.solution1(nums_q3)<<endl;
    cout << "Sum of Maximum Subarray: " << q3.solution2(nums_q3) << endl;
    cout << "Sum of Maximum Subarray: " << q3.solution3(nums_q3) << endl; // dynamic programming, not ??

    // question 2: Happy Number, no official answer
    cout << "\n ############### q2 ################" << endl;
    HappyNumber q2;
    int num = 19;
    cout << num << " is happy number: " << q2.isHappy1(num)<<endl;

        
    // question 1: find out the single number in a non-empty integer array
    vector<int> nums{ 4,1,2,1,2 }; // nums{2,1,2,2,1};
    SingleNumber q1;
    cout << "\n ############### q1 ################" << endl;
    //DisplayVector(nums);
    cout << "solution 1: " << q1.solution1(nums) << endl;
    cout << "solution 2: " << q1.solution2(nums) << endl;
    cout << "solution 2_2: " << q1.solution2_2(nums) << endl;
    cout << "solution 3: " << q1.solution3(nums) << endl;
}

