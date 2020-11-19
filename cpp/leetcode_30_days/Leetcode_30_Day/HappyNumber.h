#pragma once
#include <math.h>
using namespace std;

// function declaration
int sumOfSquares(int num);

class HappyNumber {
	/*
	https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3284/
	*/
public:
	bool isHappy1(int num) {
		try {
			num = sumOfSquares(num);
			//cout << num << " : " << endl;
			if (num == 1) {
				return true;
			}
			else {
				return isHappy1(num);
			}
		}
		catch(const runtime_error& error){
			return false; }
		
	}
};

int sumOfSquares(int num) {
	if (num != 0) {
		return pow(num % 10,2) + sumOfSquares(num / 10);
	}
	else { return 0; }
}
	