#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    string str;
    
    while(cin>>str){
        vector<int> arr(26,0);
        //cout << arr[0] << arr[12] << endl;
        int min=10000;
        int len=str.size();
        for(int i=0; i<len; i++){
            arr[str[i]-'a']++;
        }
        
        for(int i=0; i<len; i++){
            if(arr[str[i]-'a']>0 && arr[str[i]-'a']<min){
                min=arr[str[i]-'a'];
            }
        }


        for(int i=0; i<len; i++){
            if(arr[str[i]-'a']>min){
                cout << str[i];}
        }
        
        cout << endl;
    }
    return 0;
}