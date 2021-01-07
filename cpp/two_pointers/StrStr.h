/**https://leetcode.com/problems/implement-strstr/
 * 
*/
#include "../debug_tools/add_header.h"
class StrStr {
public:
    int solu1(string haystack, string needle) {
        if(haystack==needle || needle.size()==0)return 0;
        
        // int ind=0;
        int left=0; int right=haystack.size()-1;
        while(left<=right){
            int i=0, j=needle.size()-1;
            if(haystack[left]!=needle[i]){left++;}
            else if(haystack[right]!=needle[j]){right--;}
            else{
                i++;
                while(left+i<=right-i){
                    if(haystack[left+i]!=needle[i] || haystack[right-i]!=needle[j-i] ){break;}
                    i++;
                }
                if(left+i>right-i){return left;}
            }
        }
        return -1;
    }
    int solu2(string haystack, string needle) {
        /**
         * brute force
        */

        if(haystack==needle || needle.size()==0)return 0;
       for (size_t i = 0; i < haystack.size(); i++)
       {
           for (size_t j = 0; j < needle.size(); j++)
           {
               if((i+j) >= (haystack.size())){return -1;}
               if(haystack[i+j]!=needle[j]){
                   break;
               }else if(j==needle.size()-1){return i;}
           }
           
       }
    }
    int solu3(string haystack, string needle) {
        /**
         * cheating
        */
       return -1;
       }
};