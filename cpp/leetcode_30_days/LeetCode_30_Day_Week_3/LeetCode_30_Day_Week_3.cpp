// LeetCode_30_Day_Week_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include "DebugMode.h"
#include "ProductExceptSelf.h"
#include "NumIslands.h"
#include "ArraySearch.h"
#include "BstFromPreorder.h"
#include "CheckValidString.h"
#include "MinPathSum.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";


    cout << "\n########################### q1 ##########################" << endl;
    vector<int> nums_q1 = { 1,2, 3, 4,5 };
    ProductExeptSelf q1;
    DisplayVector(nums_q1);
    DisplayVector(q1.solu1(nums_q1));
    DisplayVector(q1.solu3(nums_q1));
    DisplayVector(q1.solu4(nums_q1));
    DisplayVector(q1.solu2(nums_q1));
    DisplayVector(nums_q1);


    cout << "\n########################### q2 ##########################" << endl;
    string str_q2 = "())";
    CheckValidString q2;
    cout << str_q2 << " is Valid Parenthesis String: " << q2.solu1(str_q2) << endl;


    cout << "\n########################### q3 ##########################" << endl;
    vector<vector<char>> grid_q3 = { {'1','1','0','1','0' },{'1','1','0','1','0' },{'1','1','1','1','0' },{'0','0','0','1','1' } };
    //grid_q3 = { {'1','0','0','0','0' },{'0','1','0','0','0' },{'0','0','1','0','0' },{'0','0','0','1','1' } };
    NumIslands q3;
    DisplayMatrix(grid_q3);
    cout << "number of islands: " << q3.solu1(grid_q3) << endl;
    cout << "number of islands: " << q3.solu2(grid_q3) << endl;
    cout << "number of islands: " << q3.solu3(grid_q3) << endl;
    cout << "number of islands: " << q3.solu4(grid_q3) << endl;


    cout << "\n########################### q4 ##########################" << endl;
    vector<vector<int>> grid_q4 = { {1, 3, 1},{1, 5, 1},{4, 2, 1} };
    grid_q4 = { {1, 2, 3}, { 4, 5, 6 } };
    MinPathSum q4;
    DisplayMatrix(grid_q4);
    cout << "min path: " << q4.solu1(grid_q4) << endl;
    cout << "min path: " << q4.solu2(grid_q4) << endl;


    cout << "\n########################### q5 ##########################" << endl;
    vector<int> nums_q5 = { 4,6, 7, 0, 1, 2,3 };
    int target = 0;
    ArraySearch q5;
    DisplayVector(nums_q5);
    cout << "target " << target << " at: " << q5.solu1(nums_q5, target) << endl;
    cout << "target " << target << " at: " << q5.solu2(nums_q5, target) << endl;
    cout << "target " << target << " at: " << q5.solu3(nums_q5, target) << endl;

    cout << "\n########################### q6 ##########################" << endl;


}

