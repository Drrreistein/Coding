#include "../debug_tools/DisplayData.h"

#include <iostream>
#include <vector>

// #include <algorithm>
using namespace std;
int main(){
    int m, n;
    while(cin>>m>>n)
    {
        vector<vector<int>> mat(m+1,vector<int>(n+1,0));
        for(int i=0; i<=m; i++){
            for(int j=1; j<=n; j++){

                if(i==0||j==1){
                    mat[i][j] = 1;
                }else if(i-j<0){
                    mat[i][j] = mat[i][j-1];
                }else{
                    mat[i][j] = mat[i][j-1] + mat[i-j][j];
                }
            }
        }
        DisplayMatrix(mat);
        cout << mat[m][n] << endl;
    }

    return 0;
}

/**
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int M, N;
    while (cin >> M >> N) {
        if (M < 1 || M>10 || N < 1 || N>10) {
            cout << -1 << endl;
            continue;
        }
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= N; i++) dp[0][i] = 1;
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++)
                dp[i][j] = dp[i][j - 1] + (i < j ? 0 : dp[i - j][j]);
        DisplayMatrix(dp);
        cout << dp[M][N] << endl;
    }
}
*/