#pragma once
#include <math.h>
#include <vector>

class MoveZeroes {
	/*
	Given an array nums, 
	write a function to move all 0's to the end of it 
	while maintaining the relative order of the non-zero elements.
	https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3286/

	*/
public:
	void solution1(vector<int>& nums) {
		/*
		using an additional array
		
		time: O(n)
		space: O(n)
		*/
		
		int length = nums.size();
		vector<int> res(length, 0);
		int j = 0;
		for (size_t i = 0; i < length; i++)
		{
			if (nums[i] != 0) {
				res[j++] = nums[i];
			}
		}
		nums = res;
	}

	void solution2(vector<int>& nums) {
		/*
		using no addtional array

		time: O(n2)
		space: O(1)
		*/
		int length = nums.size();
		for (int i = 0; i < length; i++) {
			if (nums[i] == 0) {
				for (int j = i + 1; j < length;j++) {
					if (nums[j] != 0) {
						nums[i] = nums[j];
						nums[j] = 0;
						break;
					}
				}
			}
		}
	}

	void solution3(vector<int>& nums) {
		/*
		using no addtional array wiht two pointers i and j 

		time: O(2n)
		space: O(1)
		*/
		int length = nums.size();
		int j = 0; // last non-zero found at j
		// operate non-zeros elements
		for (int i = 0; i < length; i++) {
			if (nums[i] != 0) {
				nums[j++] = nums[i];
			}
		}
		// operate the left zero-terms 
		for (size_t i = j; i < length; i++){
			nums[i] = 0;
		}
	}

	void solution4(vector<int>& nums) {
		/* 
		using no addtional array and two pointers 
		but efficient operation

		time: o(n)
		space O(1)
		*/
		int length = nums.size();
		int lastNonZeroFoundAt=0;
		for (size_t cur = 0; cur < length; cur++)
		{
			if (nums[cur] != 0) {
				swap(nums[lastNonZeroFoundAt++], nums[cur]);
			}
		}
	}
};