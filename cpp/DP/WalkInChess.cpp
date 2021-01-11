#include <iostream>
#include <vector>

using namespace std;
#include "../debug_tools/DisplayData.h"
int main(){
    int m,n;
    while(cin>>m>>n){
        // cout << m<< " "<< n << endl;
        vector<vector<int>> res(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j==0){
                    res[i][j]=1;
                }else{
                    res[i][j]= res[i-1][j] + res[i][j-1];
                }
            }
        }
        DisplayMatrix(res);
        cout << res[m-1][n-1] << endl;
    }
    return 0;
}