/**
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 * 
Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
 */

#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <algorithm>
bool myfunction(int i, int j);

class ThreeSum
{
public:
    vector<vector<int>> solu1(vector<int> nums)
    {
        /**
         * Brute force
         * 
         * time: O(n3)
         * space: O(n)
        */
        vector<vector<int>> mat;
        set<vector<int>> s;
        int count = nums.size();
        for (size_t i = 0; i < count; i++)
        {
            for (size_t j = i + 1; j < count; j++)
            {
                for (size_t k = j + 1; k < count; k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> tmp = {nums[i], nums[j], nums[k]};
                        // sort(tmp.begin(), tmp.end(), myfunction);
                        sort(tmp.begin(), tmp.end());
                        s.insert(tmp);
                    }
                }
            }
        }
        for (auto &x : s)
        {
            // convert set of vecctor to matrix
            mat.push_back(x);
        }
        return mat;
    }

    vector<vector<int>> solu2(vector<int> nums)
    {
        /**
         * one fixed number + two sum problem
         * 
         * time: O(n2)
         * space: O(n), a set to find out the unique solutions 
        */
        vector<vector<int>> mat;
        set<vector<int>> s;
        
        int count = nums.size();
        map<int, int>::iterator it;
        for (int i = 0; i < count; i++)
        {
            map<int, int> m;
            for (int j = i+1; j < count; j++)
            {
                /* biuld map */
                if (j != i)
                {
                    m.emplace(nums[j], j);
                }
            }
            // DisplayMap(m);
            for (int j = i+1; j < count; j++)
            {
                if (j != i)
                {
                    int key = 0 - nums[i] - nums[j];
                    it = m.find(key);
                    if (it != m.end() && it->second != j)
                    {
                        vector<int> vec={nums[i], nums[j], nums[it->second]};
                        sort(vec.begin(),vec.end());
                        if(s.find(vec)==s.end()){
                            s.insert(vec);
                            mat.push_back(vec);
                        }
                    }
                }
            }
            // DisplayMatrix(mat);
        }
        return mat;
    }

    vector<vector<int>> solu3(vector<int> nums){
        /** basically same as solu2 using two loops and a map, but will dramatically reduce time by avoiding to compute duplicate solution
         * 
         * 
        */
       vector<vector<int>> mat;
       int count=nums.size();
       sort(nums.begin(), nums.end());
       for(int i=0; i<count && nums[i]<=0; i++){
           int target = -nums[i];
           int right=count-1;
           int left=i+1;
           while(left<right){
               int sum=nums[left]+nums[right];
               if(sum>target){
                   right--;
               }else if(sum<target){
                   left++;
               }else{
                   vector<int> vec(3,0);
                   vec[0]=nums[i];vec[1]=nums[left];vec[2]=nums[right];
                   mat.push_back(vec);
                   // jump over duplicate of number2
                   while(left<right && vec[1]==nums[left]){left++;}
                   // jump over duplicate of number3
                   while(left<right && vec[2]==nums[right]){right--;}
               }
           }
           while(i+1<count && nums[i+1]==nums[i])
            {i++;}
       }
       return mat;
    }
};

bool myfunction(int i, int j) { return (i > j); }