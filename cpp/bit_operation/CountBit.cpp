#include <iostream>
#include <string>
using namespace std;

/**
 * count maximal continous count of 1 in the binary number
 * ->
 * bit operation
*/
// int main(){
//     int n;
//     while(cin>>n){
//         int count=0, maxcount=0;
//         while(n){
//             if(n&1){
//                 count++;
//                 if(count>maxcount){maxcount=count;}
//             }else{
//                 count=0;
//             }
//             n = n>>1;
//             cout << "n:" <<n;
//         }
//         cout << maxcount << endl;
//     }
//     return 0;
// }

int main(){
    int n;
    while(cin >>n){
        int k;
        for(k=0;n!=0;k++){
            n = n&(n>>1);
        }
        cout << k << endl;
    }
    return 0;
}