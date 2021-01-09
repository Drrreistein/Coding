#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<int> & vec, double add, double sum0){
    int n = vec.size();
    if(n==0){
        return false;
    }
    if(add==sum0/2){
        return true;
    }

    for (size_t i = 0; i < n; i++)
        {
            int tmp = vec[i];
            vec.erase(vec.begin()+i);
            return dfs(vec, add+tmp, sum0);
            vec.insert(vec.begin()+i,tmp);
        }
}

int main(){
    int n;
    while(cin>>n){
        vector<int> vec(n);
        int sum=0;
        
        for(int i=0; i<n; i++){
            cin >> vec[i];
            sum += vec[i];
        }

        bool res=false;
        
        

        cout << dfs(vec, 0, sum) << endl;
    }
    return 0;
}