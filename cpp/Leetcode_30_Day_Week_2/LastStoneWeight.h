#pragma once
#include <algorithm>
#include <queue>
#include "DebugMode.h";

class LastStoneWeight {
public:
    int solu1(vector<int>& stones) {
        /*
        method: recursion

        */
        if (stones.size() == 1  ) {
            return stones[0];
        }
        else if (stones.empty()) {
            return 0;
        }
        else {
            sort(stones.begin(),stones.end());
            //DisplayVector(stones);
            int t = stones.back();
            stones.pop_back();
            int s = stones.back();
            stones.pop_back();

            if (t != s) {
                stones.push_back(t - s);
            }
            //DisplayVector(stones);
            return solu1(stones);   // recursion here
        }
    }

    int solu2(vector<int>& stones) {
        /*
        methods: recursion


        */
        if (stones.size() == 1) {
            return stones[0];
        }
        else if (stones.empty()) {
            return 0;
        }
        else {
            sort(stones.begin(), stones.end(), greater<int>());
            //DisplayVector(stones);
            
            if (stones[0] != stones[1]) {
                stones.push_back(stones[0]-stones[1]);
            }
            stones.erase(stones.begin(), stones.begin() + 2);
            //DisplayVector(stones);
            return solu2(stones);   // recursion here
        }
    }

    int solu3(vector<int>& stones) {
        /*
        methods: while-loop

        */
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end(), greater<int>());
            //DisplayVector(stones);

            if (stones[0] != stones[1]) {
                stones.push_back(stones[0] - stones[1]);
            }
            stones.erase(stones.begin(), stones.begin() + 2);
            //DisplayVector(stones);
        }
        if (stones.size() == 1) {
            return stones[0];
        }
        return 0;
    }

    int solu4(vector<int>& stones) {
        /*
        methods: using priority_queue

        time: best 100%

        */
        priority_queue<int> q(stones.begin(), stones.end());
        while (q.size()>1) {
            int t = q.top(); q.pop();
            int s = q.top(); q.pop();
            if (t != s) {
                q.push(t-s);
            }
        }
        return q.empty()? 0 : q.top();
    }
};