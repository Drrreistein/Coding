#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;
#include "../debug_tools/DisplayData.h"
/**
 * string, vector, map
*/

// int main(){
//     int n;
//     cin >> n;
//     unordered_map<string, int> m;
//     vector<string> s(n,"");

//     for(int i=0; i<n; i++){
//         cin >> s[i]; 
//         m[s[i]]=0;
//     }

//     m["Invalid"]=0;
//     // DisplayMap(m);
    

//     int voter;
//     cin >> voter;
//     for (size_t i = 0; i < voter; i++)
//     {
//         string str; cin >> str;
//         if(m.find(str)!=m.end()){
//             m[str]++;
//         }else{
//             m["Invalid"]++;
//         }
//     }
//     DisplayVector(s);
//     for(int i=0; i<n; i++){
//         cout << s[i] << " : " << m[s[i]] << endl;
//     }
//     cout << "Invalid" << " : " << m["Invalid"] << endl;
//     return 0;
// }


int main(){
    int m,n;
    while(cin >> m){
        vector<string> str(m);
        unordered_map<string, int> mp;
        for (size_t i = 0; i < m; i++)
        {
            cin >> str[i];
            mp[str[i]]=0;
        }

        cin >> n;
        string s;
        for (size_t i = 0; i < n; i++)
        {
            cin >> s;
            if(mp.find(s)!=mp.end()){
                mp[s]++;
            }
        }

        int inval=n;
        for (size_t i = 0; i < m; i++)
        {
            cout << str[i] << " : " << mp[str[i]] << endl;
            inval -= mp[str[i]]; 
        }
        cout << "Invalid" << " : " << inval << endl;
        
    }
} 