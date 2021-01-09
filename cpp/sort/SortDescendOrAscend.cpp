#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * vector, 
 * algorithm: sort, 
*/

// int main(){
//     int n;{
        
//     }
//     while(cin >>n)
//     {
//         vector<int> vec(n);
//         for(int i=0; i<n; i++){
//             cin >> vec[i]; 
//         }
        
//         for(int i=1; i<n; i++){
//             for(int j=0; j<i; j++){
//                 if(vec[i]<vec[j]){
//                     int tmp=vec[i];
//                     vec[i]=vec[j];
//                     vec[j]=tmp;
//                 }
//             }
//         }
//         int desc;
//         cin >> desc;
        
//         for(int i=0; i<n; i++){
//             if(desc){
//                 cout << vec[n-i-1] << " "; 
//             }else{
//                 cout << vec[i] << " "; 
//             }
            
//         }
//         cout << endl;
//     }
    
//     return 0;
// }

bool myfunction(int m, int n){return m>n;};
int main(){
    int n;{
        
    }
    while(cin >>n)
    {
        vector<int> vec(n);
        for(int i=0; i<n; i++){
            cin >> vec[i]; 
        }

        
        int desc;
        cin >> desc;
        if(desc){
            sort(vec.begin(), vec.end(), myfunction);
        }else{
            sort(vec.begin(), vec.end());
        }
        
        for(int i=0; i<n; i++){
                cout << vec[i] << " "; 
        }
        cout << endl;
    }
    
    return 0;
}