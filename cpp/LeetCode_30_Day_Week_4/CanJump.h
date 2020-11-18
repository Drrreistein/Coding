#pragma once
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.



Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/
#include <algorithm>
class CanJump {
public:
	bool solu1(vector<int> nums) {
		/*
		wrong code for origin question
		but for question: each element represents the exact jump length at that position.
		*/
		int sum = nums[0];
		int len = nums.size();
		if (len == 1) { return true; }
		while (sum < len-1) {
			if (nums[sum] == 0) {
				break;
			}
			sum += nums[sum];
		}
		return sum == len-1 ? true : false;
	}

	bool solu2(vector<int> nums) {
		int len = nums.size();
		int i,reach = 0;
		for (i = 0; i < len && i<=reach; i++)
		{
			reach = max(reach, i+nums[i]);
		}
		return i==len; // here should be len not len-1
	}
};