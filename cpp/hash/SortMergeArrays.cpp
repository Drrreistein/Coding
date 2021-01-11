#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main(){
    int m,n;
    while(cin>>m){
        set<int> s;
        int in;
        while(m--){
            cin>>in;
            s.insert(in);
        }
        cin >> n;
        while(n--){
            cin>>in;
            s.insert(in);
        }
        for(auto x=s.begin(); x!=s.end();x++){
            cout << *x; // use pointer to get the value of iterator
        }
        cout << endl;

    }
    return 0;
}

