#pragma once
using namespace std;
#include <math.h>
#include <algorithm>
#include "DebugMode.h"
#include <unordered_map>
#include <map>
class MaxSubArray {
/*
Given an integer array nums, 
find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.
https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3285/
*/
public:
	int solution1(vector<int>& nums) {
		/*
		time: O(n2)
		space: O(1)
		*/
		int n = nums.size(); // arrat size
		int maxValue = -INFINITY; // sum of maximal Subarray
		int ind_i = 0, ind_j = 0; // lower bound and upper bound of maximal Subarray
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = i; j < n; j++) {
				sum += nums[j];
				if (sum > maxValue) {
					maxValue = sum;
					ind_i = i;
					ind_j = j;
				}
			}
		}
		return maxValue;
	}

	int solution2(vector<int>& nums) {
		/*
		time: O(n)
		space: O(1)
		*/
		int len = nums.size();
		int sum = nums[0];
		int tmp = nums[0];
		for (int i = 1; i < len; i++) {
			tmp = tmp + nums[i];
			if (nums[i] > 0) {
				if (nums[i] > sum) { 
					sum = nums[i]; 
					tmp = sum; 
				}
				else if (tmp > sum) { 
					sum = tmp;
				}
			}
			//cout << "maximum: " << i << " - " << sum << endl;
		}
		return sum;
	}

	int solution3(vector<int>& nums) {
		/*
		Method: dynamic programming 

		time: O(n)
		space: O(n)
		*/
		unordered_map<int,int> sums;
		sums.insert(pair<int, int>(nums[0], 0));
		unordered_map<int, int>::iterator it;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] <= 0) {
			}
			else {
				it= sums.end();
				it--;
				int m = max(it->first, nums[i]);
				sums.insert(pair<int, int>(m,i));
			}
			
		}
		DisplayMap(sums);
		it = sums.end();
		it--;
		return it->first; // return last element of sums vector
	}
};