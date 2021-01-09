#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        int len = s.length(); 
        bool isNum = false;
        for(int i=0; i<len; i++){
            
            if(!isNum && s.at(i)>='0' && s.at(i)<='9'){
                s.insert(i,"*");
                i++;len++;
                isNum=true;
            }
            else if(isNum && (s.at(i)<'0' || s.at(i)>'9')){
                s.insert(i,"*");
                i++;len++;
                isNum=false;
            }
        }
        if(isNum)s.insert(len,"*");
        cout << s << endl;
        
    }
    return 0;
}