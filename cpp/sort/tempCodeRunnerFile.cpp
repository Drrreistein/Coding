#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n,mode;
    string name;
    int grade;
    
    cin >> n >> mode;
    if(mode){
        map<int, string, less<int>> mp;
            for (size_t i = 0; i < n; i++)
    {
        cin >> name >> grade;
        mp[grade]=name;
        /* code */
    }

    for(auto& x: mp){
        cout << x.second << " " << x.first << endl;
    }
    }else{
        map<int, string, greater<int>> mp;
            for (size_t i = 0; i < n; i++)
    {
        cin >> name >> grade;
        mp[grade]=name;
        /* code */
    }

    for(auto& x: mp){
        cout << x.second << " " << x.first << endl;
    }
    }


    
    return 0;
}