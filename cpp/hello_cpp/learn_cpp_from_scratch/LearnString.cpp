#include <iostream>
#include <string>
using namespace std;

#include "../../debug_tools/DisplayData.h"

int main(){

    string s1="32123";
    string s2="123";

    
    cout << s1.size() << " " << s2. size() << " " << (s1.find("123")==(s1.size()-s2.size())) << endl;
    

    s2.insert(3, "*");
    cout << s2 << endl;

    return 0;

    
}