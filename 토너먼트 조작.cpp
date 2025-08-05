#include<bits/stdc++.h>
using namespace std;

int n;

void run(vector<vector<int>> &d){
    int t=n;
    while(t>1){
        for(int i=2;i<=n;i++){
            
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin>>n){
        vector<vector<int>> d(n+1, vector<int>(n+1, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                char c;
                cin>>c;
                if(c=='1') d[i][j]=1;
                else d[i][j]=0;
            }
        }    
        
        run(d);
    }
    
}