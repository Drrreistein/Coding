#pragma once

class MaxProfit {
public:
	int solu1(vector<int>& prices) {
		/*
		
		time: o(n)
		space:o(n)
		*/
		int length = prices.size();
		vector<int> delta(length - 1, 0); 
		int res=0;
		for (int i = 0; i < length-1; i++) {
			delta[i] = prices[i + 1] - prices[i];
			if (delta[i] > 0) {
				res += delta[i];
			}
		}
		return res;
	}

	int solu2(vector<int>& prices) {
		/*
		methods: sum(peaks) - sum(valleys), peaks and valleys always appear in pairs
		
		time: o(n)
		space: o(1)
		*/
		int length = prices.size();
		int res = 0;
		for (size_t i = 0; i < length; i++)
		{
			if(i==0){
				if (prices[i + 1] > prices[i]) {
					res -= prices[i]; // valley on the left bound
				}
			}
			else if (i == length - 1) {
				if (prices[i - 1] < prices[i]) {
					res += prices[i]; // peak on the right bound
				}
			}
			else {
				if (prices[i - 1] < prices[i] && prices[i + 1] < prices[i]) {
					res += prices[i]; // middle peak 
				}
				if (prices[i - 1] > prices[i] && prices[i + 1] > prices[i]) {
					res -= prices[i]; // middle peak
				}
			}
		}
		return res;

	}

	int solu3(vector<int>& prices) {
		/*
		methods: optimized solu1

		time: o(n)
		space: o(1)
		*/
		int length = prices.size();
		int res = 0;
		for (size_t i = 1; i < length; i++)
		{
			if (prices[i] > prices[i - 1]) {
				res += prices[i] - prices[i - 1];
			}
		}
		return res;
	}
};