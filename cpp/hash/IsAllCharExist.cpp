#include <iostream>
#include <string>

using namespace std;


int main(){
    string s1,s2;
    while(cin >> s1>> s2){
        int arr[26]={0};
        for(int i=0; i<s2.size();i++){
            arr[s2.at(i)-'a']=1;
        }
        string res="true";
        for(int i=0; i<s1.size();i++){
            if(arr[s1.at(i)-'a']!=1){
                res="false";
                break;
            }
        }
        cout << res << endl;
       
    }
    return 0;
}