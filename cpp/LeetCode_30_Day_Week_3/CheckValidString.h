#pragma once


/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].
*/
#include <string>
class CheckValidString {

public:
	bool solu1(string s) {
		/*
		methods: only suitable for string without '*' 

		time: 
		space: 
		*/

		int count = 0;
		int length = s.length();
		for (size_t i = 0; i < length; i++)
		{
			if (count < 0) {
				return false;
			}
			else {
				if (s[i] == '(') {
					count++;
				}
				else if (s[i] == ')') {
					count--;
				}
			}
		}
		if (count == 0) {
			return true;
		}
		return false;
	}

	bool solu2(string s) {
		/*
		methods:

		time:
		space:
		*/

		return false;
	}


	bool solu3(string s) {
		/*
		methods:

		time:
		space:
		*/

		return false;
	}

};



