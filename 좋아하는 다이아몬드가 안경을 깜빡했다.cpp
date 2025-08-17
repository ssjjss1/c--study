#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e9;
const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;

ll n, m;
vector<ll> adj[300004];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        ll u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> distS(n+4, INF), par(n+1, -1);
    queue<ll> q;
    distS[1] = 0;
    q.push(1);
    while(!q.empty()){
        ll u = q.front(); 
        q.pop();
        for(auto v: adj[u]){
            if(distS[v] == INF){
                distS[v] = distS[u] + 1;
                par[v] = u;                 
                q.push(v);
            }
        }
    }

    vector<ll> distT(n+4, INF);
    distT[n] = 0;
    q.push(n);
    while(!q.empty()){
        ll u = q.front(); 
        q.pop();
        for(auto v: adj[u]){
            if(distT[v] == INF){
                distT[v] = distT[u] + 1;
                q.push(v);
            }
        }
    }

    vector<ll> cntS(n+1, 0), cntT(n+1, 0);

    vector<ll> od(n);
    iota(od.begin(), od.end(), 1);
    sort(od.begin(), od.end(), [&](ll a, ll b){
        return distS[a] < distS[b];
    });

    cntS[1] = 1; 
    ll D = distS[n];
    for(auto u : od){
        if(distS[u] == INF) break; 
        if(distS[u] + distT[u] > D) continue; 
        for(auto v : adj[u]){
            if(distS[v] == distS[u] + 1 && distS[v] + distT[v] == D){
                cntS[v] += cntS[u]; 
                cntS[v] %= MOD1;
            }
        }
    }

    sort(od.begin(), od.end(), [&](ll a, ll b){
        return distS[a] > distS[b];
    });

    cntT[n] = 1; 
    for(auto u : od){
        if(distS[u] == INF) continue;
        if(distS[u] + distT[u] > D) continue;
        for(int v : adj[u]){
            if(distS[v] == distS[u] + 1 && distS[v] + distT[v] == D){
                cntT[u] += cntT[v]; 
                cntT[u] %= MOD1;
            }
        }
    }

    ll res = cntS[n];

    for(int i=2; i<n; i++){
        if(distS[i] + distT[i] != D) continue; 
        long long temp = (1LL * cntS[i] * cntT[i]) % MOD1;
        if(temp == res){
            cout<<i;
            return 0;
        }
    }

    cout << 1;
}