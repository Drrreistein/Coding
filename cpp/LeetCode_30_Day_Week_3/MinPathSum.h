#pragma once
/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
*/
#include <algorithm>

using namespace std;

class MinPathSum {
public:
	int solu1(vector<vector<int>> grid) {
		/*
		methods: dp

		time: O(n2)
		space: O(n2)
		*/

		vector<vector<int>> ans = grid;
		int m = grid.size();
		int n = m ? grid[0].size() : 0;
		for (int i = 1; i < m; i++) {// first column
			ans[i][0] = ans[i - 1][0] + grid[i][0];
		}
		for (int i = 1; i < n; i++) {// first row
			ans[0][i] = ans[0][i - 1] + grid[0][i];
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				ans[i][j] = min(ans[i][j - 1], ans[i - 1][j]) + grid[i][j];
			}
		}
		return ans[m - 1][n - 1];
	}

	int solu2(vector<vector<int>> grid) {
		/*
		methods: dp

		time: O(n2)
		space: O(1)
		*/

		int m = grid.size();
		int n = m ? grid[0].size() : 0;
		for (int i = 1; i < m; i++) {// first column
			grid[i][0] = grid[i - 1][0] + grid[i][0];
		}
		for (int i = 1; i < n; i++) {// first row
			grid[0][i] = grid[0][i - 1] + grid[0][i];
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				grid[i][j] = min(grid[i][j - 1], grid[i - 1][j]) + grid[i][j];
			}
		}
		return grid[m - 1][n - 1];
	}
};