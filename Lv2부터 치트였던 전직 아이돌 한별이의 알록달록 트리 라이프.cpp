#include<bits/stdc++.h>
#define INF 300004
using namespace std;

vector<long long> adj[INF];
vector<vector<long long>> dp(INF, vector<long long>(4, 0));

long long dfs(int node, int p, int gp){
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        long long u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long re = dfs(1, -1, -1);

}