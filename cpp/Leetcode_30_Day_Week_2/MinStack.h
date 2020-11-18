#pragma once
using namespace std;
#include <stack>;

class MinStack {
    /*
    methods: using build-in stack container

    time: O(1)
    space: O(n)
    */
public:
    /** initialize your data structure here. */
    int minEle;
    stack<int> s;

    MinStack() {
    }

    void push(int x) {
        if(s.empty()){
            minEle = x;
            s.push(x);
        }
        else {
            // encoding value in stack using the minEle information, to get a better time complexity
            if (x < minEle) {
                s.push(2 * x - minEle);
                minEle = x;
            }
            else {
                s.push(x);
            }
        }
    }

    void pop() {
        int t = s.top();
        s.pop();
        if (t < minEle) {
            minEle = 2 * minEle - t;
        }
    }

    int top() {
        if (s.empty()) {
            cout << "empty stack, no top value" << endl;
        }
        else {
            int t = s.top();
            if (t < minEle) {
                return minEle;
            }
            else {
                return t;
            }
            
        }
    }

    int getMin() {
        if (s.empty()) {
            cout << "empty stack, no min value" << endl;
        }
        else {
            return minEle;
        }
        
    }
    int getSize() {
        return s.size();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */