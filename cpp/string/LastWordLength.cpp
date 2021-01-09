#include <iostream>
#include <string>

using namespace std;
/**
 * difference btw.
 * getline()
 * cin>>
*/

// int main(){
//     string str; 
//     while(getline(cin, str)){
//         int count=0;
//         for(int i=0; i<str.size(); i++){
//             if(str.at(i)==' '){
//                 count=0;
//             }else{
//                 count++;
//             }
//         }
//         cout << count << endl;
//     }
//     return 0;
// }

int main(){
    string str; 
    while(cin>>str);
    cout << str.size() << endl;
    return 0;
}