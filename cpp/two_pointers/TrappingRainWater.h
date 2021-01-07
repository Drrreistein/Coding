/**
 * https://leetcode.com/problems/trapping-rain-water/
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 * compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.
*/

#include "../debug_tools/add_header.h"

class TrappingRainWater{
public:

    int solu1(vector<int>& nums){
        /**brute force
         * 
        */
        int count=nums.size();
        int ans=0;

        for (int i=0; i < count; i++)
        {
            int left_max=nums[i], right_max=nums[i];

            for(int j=i-1; j>=0; j--){
                left_max = max(left_max, nums[j]);
            }

            for(int j=i+1; j<count; j++){
                right_max = max(right_max, nums[j]);
            }
            ans += min(left_max, right_max)-nums[i];
            // cout << ans << ", \n";
        }
        return ans;
    }
    int solu2(vector<int>& nums){
        /**dp
         * 
        */
        int count=nums.size();
        vector<int> ans(count,0);
        int sum=0;
        for (int i=1, p=0; i < count; i++)
        {
            sum +=nums[i];
            ans[i]=ans[p]+(i-p-1)*min(nums[i],nums[p])-sum;
            if(nums[i]>nums[p]){
                p=i;
                sum=0;
            }
        }
        
        return ans[count-1];
    }
};