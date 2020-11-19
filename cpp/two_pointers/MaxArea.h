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
        int p=0,q=1;
        int ans=0;
        for (int i = 2; i < height.size(); i++)
        {
            int area1 = (i-p) * min(height[i], height[p]);
            int area2 = (i-q) * min(height[i], height[q]);
            if(area2>area1){
                if(area2>ans){
                    p=q;
                    ans=area2;
                }
            }else{
                if(area1>ans){
                    ans=area1;
                }
            }
            if(height[i]>height[q]){
                q=i;
            }
            
        }
        return ans;
    }

    int solu2(vector<int>& height){
        int len= height.size();
        int ans=0;
        for (int i = 0; i < len-1; i++)
        {
            for(int j = i+1; j < len; j++){
                int area=(j-i)*min(height[i],height[j]);
                cout << area<<endl;
                if(area > ans){
                    ans=area;
                }
            }
            return ans;
        }
        
    }

};