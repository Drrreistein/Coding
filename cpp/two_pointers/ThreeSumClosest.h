/**
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include "../debug_tools/add_header.h"

class ThreeSumClosest
{
public:
    int solu1(vector<int>& nums, int target)
    {
        /** fix one number + method of two-sum problem
         * time: O(n2)
         * space: O(n)
        */
       int count=nums.size();
    //    vector<int> ans(3,0);
       sort(nums.begin(), nums.end());
       int ans= nums[0]+nums[1]+nums[2];
       for (int i = 0; i < count; i++)
       {
           /* code */
           int left=i+1;
           int right=count-1;
           while(left<right){
               int sum=nums[i]+nums[left]+nums[right];
                if(abs(ans-target)>abs((sum-target))){
                   ans=sum;
               }
               if(sum>target){right--;}
               else if(sum<target){left++;}
               else{return ans;}
               
           }
       }
       return ans;
    }
};