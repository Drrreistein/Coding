#pragma once
/**
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
*/
#include <vector>
#include "DebugMode.h"
using namespace std;

class ProductExeptSelf {
public:
	vector<int> solu1(vector<int>& nums) {
        /*
        methods: dp

        time O(n2)
        space O(n)
        */
        vector<int> ans = nums;
        int p0 = ans[1], p1;
        ans[0] = nums[1]; ans[1] = nums[0];

        for (int i = 2; i < nums.size(); i++) {
            p1 = ans[i];
            ans[i] = ans[i - 1] * p0;
            p0 = p1;
            for (int j = 0; j < i; j++) {
                ans[j] = ans[j] * p1;
            }
        }
        return ans;
	}

    vector<int> solu2(vector<int>& nums) {
        /*
        method: dp
        
        time: O(n)
        space: O(1)
        */
        int p0 = nums[1], p1;
        nums[1]=nums[0]; 
        nums[0] = p0;

        for (int i = 2; i < nums.size(); i++) {
            p1 = nums[i];
            nums[i] = nums[i - 1] * p0;
            p0 = p1;
            for (int j = 0; j < i; j++) {
                nums[j] = nums[j] * p1;
            }
            //DisplayVector(nums);
        }
        return nums;
    }

    vector<int> solu3(vector<int>& nums) {
        /*
        methods: left factorial and right factorial

        time: O(n)
        space: O(n)
        */
        int len = nums.size();
        vector<int> ans = nums;
        vector<int> left = nums;
        left[0] = 1;
        vector<int> right = nums;
        right[len-1] = 1;

        for (size_t i = 1; i < len; i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }
        for (int i = len-2; i >=0; i--)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }
        for (size_t i = 0; i < len; i++)
        {
            ans[i] = left[i] * right[i];
        }
        return ans;
    }

    vector<int> solu4(vector<int>& nums) {
        /*
        methods: left factorial and right factorial

        time: O(n)
        space: O(1)
        */

        int len = nums.size();
        vector<int> ans = nums;
        ans[0] = 1;
        int R = 1;
        for (size_t i = 1; i < len; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
            
        }
        for (int i = len-2; i >=0; i--)
        {
            R = R * nums[i+1];
            ans[i] = ans[i]*R;
        }
        return ans;
    }
};