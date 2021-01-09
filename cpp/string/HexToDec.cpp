#include <iostream>
using namespace std;

#include <string>

int main()
{
    string s;
    
    while(getline(cin, s)){
        int sum = 0;
        int prod=1;
        for(int i=s.size()-1; i>=2; i--){
            if(s.at(i)>='0' && s.at(i)<='9'){
                sum += (s.at(i)-'0')*prod;
            }
            else if(s.at(i)>='A' && s.at(i)<='F'){
                sum += (s.at(i)-'A'+10)*prod;
            }
            prod *= 16;
        }
        cout << sum << endl;
    }
    return 0;
}



// int main()
// {
//     int s;
//     while(cin>>hex>>s){
//         cout << s << endl;
//     }
    
//     return 0;
// }