#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;

ll MOD_POW(ll x, ll exp) {
    ll res = 1;
    x %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        exp /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> v(m + 4);

    for (int i = 0; i < n; i++) {
        int l, r;
        ll p, q;
        cin >> l >> r >> p >> q;
        ll prob = p * MOD_POW(q, MOD - 2) % MOD;
        v[r].emplace_back(l, prob);
    }

    vector<ll> dp(m + 4, 0);
    vector<ll> pre(m + 4, 0);

    dp[0] = 1;
    pre[0] = 1;

    for (int i = 1; i <= m; i++) {
        for (auto [l, prob] : v[i]) {
            ll sum = pre[i - 1] - (l > 1 ? pre[l - 2] : 0);
            sum = (sum + MOD) % MOD;
            dp[i] = (dp[i] + sum * prob % MOD) % MOD;
        }
        pre[i] = (pre[i - 1] + dp[i]) % MOD;
    }

    cout << dp[m];
}