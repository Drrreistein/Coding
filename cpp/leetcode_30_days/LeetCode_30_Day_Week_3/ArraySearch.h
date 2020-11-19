#pragma once
/*
https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14435/Clever-idea-making-it-simple

You are given an integer array nums sorted in ascending order, and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
*/
using namespace std;

#include "DebugMode.h"

class ArraySearch {

public:
    int solu1(vector<int> nums, int target) {
        /*
        methods: directly

        time: O(n)
        space: O(1);
        */

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }

    int solu2(vector<int> nums, int target) {
        /*
        methods: binary search

        time: O(lg(n))
        space: O(1);
        */

        int start = 0;
        int len = nums.size();
        int end = len-1;
        int mid;
        while (end > start) {// find the index of smallest value
            mid = (start + end) / 2;
            if (nums[mid] > nums[end]) {
                start = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        //cout << "start: " << start << " end: " << end << endl;

        int ind = end; // index of smallest value
        start = 0; end = len - 1;
        int realMid;
        while (start<=end)
        { // binary search and take rotation into consideration
            mid = (start + end)/2 ;
            realMid = (mid + ind) % len;
            if (nums[realMid] > target) {
                end = mid-1;
            }
            else if (nums[realMid] < target) {
                start = mid+1;
            }
            else {
                return realMid;
            }
        }
        return -1;
    }

    int solu3(vector<int> nums, int target) {
        /*
        methods: decide if nums[mid] and target is in the same or opposite side, then do binary search

        time: O(lg(n))
        space: O(1);
        */

        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if ((nums[mid] - nums[0]) * (target- nums[0]) > 0) { //mid and target in the same side
                if (target < nums[mid]) {
                    end = mid -1;
                }else{
                    start = mid + 1;
                }
            }
            else { // mid and target in opposite side
                if (target>nums[mid]) {
                    end = mid-1 ;
                }
                else {
                    start = mid + 1;
                }
            }
        }
        // now start==end
        if (nums[end] == target) {
            return end;
        }
        else {
            return -1;
        }

    }
};
