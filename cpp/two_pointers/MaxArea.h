/**
 * https://leetcode.com/problems/container-with-most-water/
 * Given n non-negative integers a1, a2, ..., an , 
 * where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two 
 * endpoints of the line i is at (i, ai) and (i, 0). 
 * Find two lines, which, together with the x-axis 
 * forms a container, such that the container contains
 *  the most water.
 * 
 * Notice that you may not slant the container.
 *
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class MaxArea{
public:
    int solu1(vector<int>& height){
        /**
         * methods: two pointer
         * time:O()
         */
        int len = height.size();
        int l=0,r=len-1;
        int ans=0;
        while(l<r){
            cout << "l: " << l << " r: " << r << " area: "<< ans <<endl;
            ans = max(ans, min(height[l],height[r])*(r-l));
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }

    int solu2(vector<int>& height){
        int len= height.size();
        int ans=0;
        for (int i = 0; i < len; i++)
        {
            for(int j = i; j < len; j++){
                int area=(j-i)*min(height[i],height[j]);
                // cout << area<<endl;
                if(area > ans){
                    ans=area;
                }
            }
        }
        return ans;
    }

};