#pragma once
#include <algorithm>
#include <unordered_map>
#include <map>
/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
*/

class FindMaxLength {
public:
    int solu1(vector<int>& nums) {
        /*
        methods: brute force

        */
        for (size_t i = 0; i < nums.size(); i++)
        {
            int len = nums.size() - i;
            for (size_t j = 0; j <= i; j++)
            {
                int count = 0;
                for (size_t k = j; k < j+len; k++)
                {
                    nums[k] == 0 ? count-- : count++;
                }
                if (count == 0) { return len; }
            }
        }
        return 0;

    }

    int solu2(vector<int>& nums) {
        /*
        methods: using count array in size of 2n+1, count the maximal distance of indices in that count;
        
        */
        int n = nums.size();
        int* begin,*end;
        begin = new int[2 * n + 1]{}; // initialization array element as 0
        int count = 0,ans = 0 ;
        for (size_t i = 0; i < 2*n+1; i++)
        {
            begin[i] = -1;
        }
        for (size_t i = 0; i < n; i++)
        {
            nums[i] ? count++ : count--;
            if (begin[count + n] == -1 && count!=0) {
                    begin[count + n] = i;
            }
            else { 
                
                int m = i - begin[count + n];
                ans = max(ans,m);
            }

        }

        return ans;
    }

    int solu3(vector<int>& nums) {
        /*
        methods: using count array in size of 2n+1, count the maximal distance of indices in that count;

        */
        unordered_map<int, int> m;
        m.insert(pair<int,int>(0,-1));
        
        int count = 0;
        int ans = 0;
        int h = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            nums[i] ? count++ : count--;
            if(m.count(count)==0){
                m[count] = i;
            }
            //m.insert(pair<int, int>(count, i)); // insert operation will fail when the key exists already 
            
            //cout << " " << count << " " << i << " " << m[count]<<endl;
            h = i - m[count];
            ans = max(ans, h);
            
        }
        return ans;
    }
};