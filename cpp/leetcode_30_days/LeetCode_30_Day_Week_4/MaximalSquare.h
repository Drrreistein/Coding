#pragma once
/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/
using namespace std;
#include <vector>
#include "DebugMode.h"
#include <cmath>

class MaximalSquare {
public:
    int solu1(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        int ans = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1)); // initialization, all elements are 0
        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++)
            {
                if(matrix[i][j]==1){
                    dp[i+1][j+1] = min(min(dp[i][j], dp[i][j+1]), dp[i+1][j]) + 1;
                    if(ans<dp[i+1][j+1]){ // update ans
                        ans = dp[i+1][j+1];
                    }
                }
            }
        }
        // DisplayMatrix(dp);
        return pow(ans,2);
    }

    int solu2(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        int ans = 0;
        vector<vector<int>> dp(2, vector<int>(n+1)); // initialization, all elements are 0
        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++)
            {
                if(matrix[i][j]==1){
                    dp[(i+1)%2][j+1] = min(min(dp[(i)%2][j], dp[(i)%2][j+1]), dp[(i+1)%2][j]) + 1;
                    if(ans<dp[(i+1)%2][j+1]){ // update ans
                        ans = dp[(i+1)%2][j+1];
                    }
                }else{
                    dp[(i+1)%2][j+1] = 0;
                }
            }
            // DisplayMatrix(dp);
        }
        return pow(ans,2);
    }
};