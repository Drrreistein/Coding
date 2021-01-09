#include <iostream>
using namespace std;
#include <map>
#include <string>
#include "../debug_tools/DisplayData.h"

int main(){
    /** ordered Hashmap
     * space O(n)
     * time: O(n2)
     */
    // map<char, int> m;
    // string str;
    // while(getline(cin, str)){
    //     for(int i=0; i<str.length(); i++){
    //         m[str.at(i)]++;
    //     }
    //     DisplayMap(m);
    //     string res="";

    //     while(m.begin() !=m.end()){
    //         map<char, int>::iterator it = m.begin();
    //         for(auto x=m.begin(); x!=m.end(); ++x){
    //             if(x->second > it->second)
    //                 it = x;
    //         }
    //         res = res + (it->first);
    //         m.erase(it->first);
    //     }
    //     cout << res << endl;
    // }

    /**
     * char + stirng 
    */
   string str;
   int count[256]={0};
   
   while(getline(cin, str)){
       int max=0;
       for(int i=0; i<str.length(); i++){
           count[str.at(i)]++;
           if(count[str.at(i)]>max){
               max = count[str.at(i)];
           }
       }
       while(max){
            for(int i=0; i<256; i++){
                if(count[i]==max){
                    printf("%c",i);
                }
                    
            }
            max--;
       }
       printf("\n");
       
   }
    return 0;
}