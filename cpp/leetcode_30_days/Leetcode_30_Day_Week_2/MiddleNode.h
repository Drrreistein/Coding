#pragma once
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MiddleNode {
public:
    ListNode* solu1(ListNode* head) {
        vector<ListNode*> A = { head };

        while (A.back()->next != NULL) {
            A.push_back(A.back()->next);
        }
        return A[A.size() / 2];
    }
};