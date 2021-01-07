/**
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

// #include <map>
// #include <vector>
// using namespace std;

#include "../debug_tools/add_header.h"

class TwoSum
{
public:
    vector<int> solu1(vector<int> &nums, int target)
    {
        /**
         * using hash map
         * time O(n)
        */
        map<int, int> m;
        vector<int> ans;
        for (size_t i = 0; i < nums.size(); i++)
        {
            m.insert(pair<int, int>(nums[i], i));
        }

        for (size_t i = 0; i < nums.size(); i++)
        {
            /* code */
            int key = target - nums[i];
            if (m.find(key) != m.end() && m.find(key)->second != i)
            {
                // int tmp=m.find(key)->second;
                ans.push_back(m.find(key)->second);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }

    vector<int> solu2(vector<int> &nums, int target)
    {
        /**
         * brute force
         * time: O(n2)
        */
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }

    vector<int> solu3(vector<int> &nums, int target)
    {
        /**
         * sort vector first then use two pointers
         * time: O(n)
        */
        vector<int> ans;
        int count=nums.size();
        sort(nums.begin(), nums.end());
        int left=0;
        int right=count-1;
        while(left<right){
            int sum=nums[left]+nums[right];
            if(sum==target){
                return vector<int>{left, right};
            }else if(sum<target){
                left++;
            }else{
                right--;
            }
        }
        return vector<int>(2,0);
    }
};