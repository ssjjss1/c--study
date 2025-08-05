#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c,k;
    cin>>a>>b>>c>>k;

    vector<vector<int>> dp(k+1, vector<int>(4, -1));
    dp[0][0] = 0;

    for(int i=0;i<=k;i++){
        for(int j=0;j<4;j++){
            if(dp[i][j]==-1) continue;
            if(i+a<=k){
                int d = (j+3)%4;
                if(dp[i+a][d]==-1 || dp[i+a][d]>dp[i][j]+1)
                    dp[i+a][d]=dp[i][j]+1;
            }
            if(i+b<=k){
                int d = (j+1)%4;
                if(dp[i+b][d]==-1 || dp[i+b][d]>dp[i][j]+1)
                    dp[i+b][d]=dp[i][j]+1;
            }
            if(i+c<=k){
                int d = (j+2)%4;
                if(dp[i+c][d]==-1 || dp[i+c][d]>dp[i][j]+1)
                    dp[i+c][d]=dp[i][j]+1;
            }
        }
    }
    cout << dp[k][0];
}