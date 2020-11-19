#pragma once
#include <map>
#include <unordered_map>

using namespace std;


bool arrayRemove(vector<int>& array, double element) {
	// remove specified element out of array
	for (auto x : array) {
		if (x == element) {
			auto tmp = x;
			x = array.at(array.size()-1);
			array.at(array.size() - 1) = tmp;
			array.pop_back();
			return true;
		}
	}
	return false;
}

class SingleNumber {
	/*
	https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3283/
	*/
public:
	int solution1(vector<int>& nums) {
		/*	
		Methods: create a extra array no_duplicate_arr, 
		Iterate through all elements in nums 
			push the element in no_duplicate_arr, which no_duplicate_arr doesnt have.
			pop the element out of no_duplicate_arr, which is already in _no_duplicate_arr
		return the final left element in no_duplicate_array

		time complexity: O(n2)
		space complexity: O(n)
		*/
		vector<int> no_duplicate_arr;
		
		for (auto x : nums) {
			if(arrayRemove(no_duplicate_arr, x)){
			}
			else {
				no_duplicate_arr.push_back(x);
			}
		}
		return no_duplicate_arr[0];
	}



	int solution2(vector<int>& nums) {
		/*
		Method: using Hashmap,
		Iterate through all elements in nums,
		compute how many times each element appears
		return the element which only appear once

		time complexity: O(n)
		space complexity:O(n)
		*/
		map<int, int> m;
		map<int, int>::iterator it;

		for (auto x : nums) {
			it = m.find(x);
			if (it != m.end()) { m.at(x)++; }
			else { m.insert(pair<int, int>(x, 1)); }
		}
		
		for (auto& x : m) {
			if (x.second == 1) {
				return x.first;
			}	
		}
		return 0;
	}
	int solution2_2(vector<int>& nums) {
		/*
		Method: hash map

		time: O(n)
		space: O(n)
		*/
		map<int, int> m;
		for (auto x : nums) {
			if (!m[x]) {
				m[x] = 1;
			}
			else {
				m.erase(x);
			}
		}
		return m.begin()->first;
	}

	int solution3(vector<int>& nums) {
		/*
		XOR/Bitweise Operation

		time complexity: O(n)
		space complexity: O(1)
		*/
		int m = 0;
		for (int x : nums) { 
			m = m^x; 
		}
		return m;
	}
};	