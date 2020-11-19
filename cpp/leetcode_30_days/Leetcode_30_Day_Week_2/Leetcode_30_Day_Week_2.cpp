// Leetcode_30_Day_Week_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include "BackspaceCompare.h"
#include "DiameterOfBinaryTree.h"
#include "FindMaxLength.h"
#include "LastStoneWeight.h"
#include "MiddleNode.h"
#include "MinStack.h"

using namespace std;

int main()
{
    // test
    string test = "123456";
    test.erase(test.end() - 1);
    //cout << test << endl;
    test = &test[1];
    //cout << test << endl;
    // test map
    map<int, int> m;
    m.insert(pair<int, int>(-1, 2));
    m.insert(pair<int, int>(-2, 1));
    //cout << " " << m.count(-2) << endl;

    // question 6: Last Stone Weight
    cout << "######################## q6 #########################" << endl;
    vector<int> arr_q6 = {0, 0, 1, 0, 0, 0, 1, 1};
    //arr_q6 = { 0,0,1 };
    FindMaxLength q6;
    cout<< q6.solu1(arr_q6) << endl;
    cout << q6.solu2(arr_q6) << endl;
    cout << q6.solu3(arr_q6) << endl;

    // question 5: Last Stone Weight
    cout << "######################## q5 #########################" << endl;
    vector<int> arr_q5 = { 2, 7, 4, 1, 8, 1 };
    LastStoneWeight q5;
    cout << q5.solu1(arr_q5) << endl;
    arr_q5 = { 2, 7, 4, 1, 8, 1 };
    cout << q5.solu2(arr_q5) << endl;
    arr_q5 = { 2, 7, 4, 1, 8, 1 };
    cout << q5.solu3(arr_q5) << endl; // while-loop
    arr_q5 = { 2, 7, 4, 1, 8, 1 };
    cout << q5.solu4(arr_q5) << endl; // while-loop, priority-queue

    // question 4 Diameter of Binary Tree
    cout << "######################## q4 #########################" << endl;

    // question 3 Min Stack
    cout << "######################## q3 #########################" << endl;
    MinStack* q3=new MinStack();
    q3->push(1);
    q3->push(3);
    q3->push(-1);
    q3->pop();
    cout << "stack size: "<<q3->getSize() << ", minStack: "<< q3->getMin() << ", topStack: " << q3->top()<<endl;

    // question 2: 
    string S = "a#b#c", T = "ad##c";
    BackspaceCompare q2;
    cout << "######################## q2 #########################" << endl;
    cout << S << " and " << T << " equal: " << q2.solu2(S, T) << endl;
    cout << S << " and " << T << " equal: " << q2.solu3(S, T) << endl;
    cout << S << " and " << T << " equal: " << q2.solu4(S, T) << endl;
    cout << S << " and " << T << " equal: " << q2.solu5(S, T) << endl; 


    // question 1: Middle of the Linked List
    cout << "######################## q1 #########################" << endl;
    vector<int> q1_nums = { 1,2,3,4,5 };
    // build linked listnode
    //ListNode head(q1_nums[0]);
    //for (size_t i = 0; i < q1_nums.size(); i++)
    //{
    //    ListNode tmp(q1_nums[i])
    //    head.next
    //    if (i != q1_nums.size()) {

    //    }
    //    else {

    //    }
    //}


    std::cout << "Hello World!\n";
}

