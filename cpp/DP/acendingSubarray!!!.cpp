#include <iostream>
using namespace std;
#include <vector>
#include "../debug_tools/DisplayData.h"

int main(){
    int m;
    while(cin>>m){
        vector<int> data(m,0);
        vector<int> dp(m,1);
        // int res=0;
        // cout << res << endl;
        for(int i =0; i<m; i++){
            cin >> data[i];
            //dp[i]=dp[i-1];
            for(int j=0; j<i; j++){
                if(data[j]<data[i])
                    dp[i] = max(dp[j]+1, dp[i]);
                else                
                    dp[i] = max(dp[j], dp[i]);
                
            }
            // res=max(res, dp[i]);
        }
        DisplayVector(dp);
        cout << dp[m-1] << endl;
    }
    
    return 0;
}