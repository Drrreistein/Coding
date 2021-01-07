#include <iostream>
using namespace std;

int gcd(int m, int n)
    // greatest common divider
{
    while(m%n){
        int tmp=m;
        m=n;
        n=tmp%n;
    }
    return n;
}

int main(){
    int a, b;
    while(cin >>a>>b){
        cout <<a*b/gcd(a,b) << endl;
    }
    return 0;
}