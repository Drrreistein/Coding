#pragma once

/*
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.



Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
*/
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

class SubarraySum {
public:
	int solu1(vector<int>& nums, int k) {
		/*
		only suitable for vector with all positive elements.
		*/
		set<int> sum;
		sum.insert(0);
		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum.insert(*--sum.end()+nums[i]);
		}
		for (set<int>::iterator x = sum.begin(); x != sum.end();x++) {
			if (sum.find(*x + k) != sum.end() && sum.find(*x + k)!=x) {
				ans++;
			}
		}
		return ans;
	}

	int solu2(vector<int>& nums, int k) {
		/*
		only suitable for vector with all positive elements.
		*/
		unordered_map<int, int> m;
		m[0] = 1;
		int ans = 0, sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			ans += m[sum - k];
			m[sum]++;
		}
		return ans;
	}

};