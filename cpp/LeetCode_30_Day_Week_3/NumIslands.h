#pragma once
/**
Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.



Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/


#include <vector>
#include <algorithm>

#include "DebugMode.h"

using namespace std;

class NumIslands {
public:
    int solu1(vector<vector<char>> grid ){
        /*
        methods: tranverse grid, check each '1' neighbor of current point, if one neighbor already in 

        time: 
        space: 
        */
        int count = 0;
        map<int, int> m;
        int col = grid[0].size(); 
        int row = grid.size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1') { // find land
                    int tmp = i * col + j ;
                    vector<int> neighbarLand = findLandNeigh(grid, {i,j});
                    if (neighbarLand.empty()) { // isolated land
                        count++;
                        m[tmp]= count;
                    }
                    else { // not isolated land
                        if (m.empty()) { // empty map
                            count++; 
                            m[tmp] = count;
                            continue;
                        }

                        int haha = 0; // 1 means find one neighbar in the map
                        for (int k = 0; k < neighbarLand.size(); k++) // traverse neighbar
                        {
                            
                            auto x = m.begin();
                            for (; x != m.end(); x++) { // tranverse map to find if neighbar already in the map
                                if (x->first == neighbarLand[k]) {
                                    m[tmp] = x->second;
                                    haha = 1;
                                    break;
                                }
                            }
                            if (haha) {
                                break;
                            }
                        }
                        if (!haha) { // empty map
                            count++;
                            m[tmp] = count;
                        }
                        

                    }
                }
            }
        }
        DisplayMap(m);
        return count;
    }
    vector<int > findLandNeigh(vector<vector<char>> grid, vector<int> ind) {
        int col = grid[0].size();
        int row = grid.size();
        vector<int> ans;
        vector<vector<int>> neigh = { {ind[0] - 1,ind[1]},{ind[0],ind[1] - 1},{ind[0],ind[1] + 1},{ind[0] + 1,ind[1]} };
        for (size_t i = 0; i < 4; i++)
        {
            int m = neigh[i][0], n = neigh[i][1];
            if (m>= row || m<0 || n>=col|| n < 0) {
                continue;
            }
            else {
                if (grid[m][n] == '1') {
                    ans.push_back(m * col + n);
                }
            }
        }
        return ans;
    }

    int solu2(vector<vector<char>> grid) {
        /*
        methods: dfs,

        time:
        space:
        */
        int ans = 0;
        int m = grid.size();
        int n= m ? grid[0].size() : 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1') {
                    ans++;
                    DFS(grid, m, n, i, j);
                    DisplayMatrix(grid);
                }
            }
        }
        return ans;
    }
    void DFS(vector<vector<char>>& grid, int m, int n, int i, int j) {
        if (i >= m || j >= n || i < 0 || j < 0) {
            return;
        }
        else if (grid[i][j] == '1') {
            grid[i][j] = '0';
            DFS(grid, m, n, i-1, j);
            DFS(grid, m, n, i , j-1);
            DFS(grid, m, n, i , j+1);
            DFS(grid, m, n, i+1 , j);
        }
    }

    int solu3(vector<vector<char>> grid) {
        /*
        methods: dfs, erases all connected '1'

        time:
        space:
        */

        return 0;
    }

    int solu4(vector<vector<char>> grid) {
        /*
        methods: bfs,using a queue

        time:
        space:
        */

        return 0;
    }
};