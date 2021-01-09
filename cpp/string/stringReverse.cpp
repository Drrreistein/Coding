#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

int main(){
    string str;
    while(getline(cin, str)){
        // int len = str.length();
        // for(int i=0; i<len/2; i++){
            
        //     string tmp = str.substr(i,1);
        //     str.replace(i,1,str.substr(len-i-1,1));
        //     str.replace(len-i-1,1,tmp);
            
        // }
        reverse(str.begin(), str.end());
        cout << str << endl;
    }
    return 0;
}