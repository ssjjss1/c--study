#include <bits/stdc++.h>
#define INF 300004
using namespace std;
typedef long long ll;

vector<int> adj[INF];
vector<vector<ll>> dp(INF, vector<ll>(4, 0));
int n;
ll m;

void dfs(int cx, int p) {
    vector<ll> res(4);
    res[0] = 1;
    res[1] = 0;
    res[2] = 1;
    res[3] = 0;

    for (auto nx : adj[cx]) {
        if (nx == p) continue;
        dfs(nx, cx);
        
        vector<ll> temp(4);
        temp[0] = res[0] * ((dp[nx][0] + dp[nx][1]) % m) % m;
        temp[1] = (res[1] * ((dp[nx][0] + dp[nx][1]) % m) + res[0] * dp[nx][2]) % m;
        temp[2] = res[2] * ((dp[nx][2] + dp[nx][3]) % m) % m;
        temp[3] = (res[3] * ((dp[nx][2] + dp[nx][3]) % m) + res[2] * dp[nx][0]) % m;

        res = temp;
    }

    dp[cx][0] = res[0] % m;
    dp[cx][1] = res[1] % m;
    dp[cx][2] = res[2] % m;
    dp[cx][3] = res[3] % m;
}

ll mPow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    ll total = mPow(2, n, m);
    ll re = (dp[1][0] + dp[1][1] + dp[1][2] + dp[1][3]) % m;
    ll ans = (total - re + m) % m;

    cout << ans;
}