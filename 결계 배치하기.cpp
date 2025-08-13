#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll s = n / m;

    vector<ll> dp(k+4, 0);
    for(int i = 1; i <= k; i++){
         dp[i] = 1;
    }

    for(ll i = 1; i <= m-1; i++){
        ll l = a[i*s];
        ll r = a[i*s + 1] - 1;

        vector<ll> temp(k+4, 0); 

        for(ll j = 1; j <= k; j++){
            if(!dp[j]) continue;

            ll lo = max(j + 1, 2*l - j);
            ll hi = min(k, 2*r + 1 - j);
            if(lo <= hi){
                temp[lo] = (temp[lo] + dp[j]) % MOD;
                temp[hi + 1] = (temp[hi + 1] - dp[j] + MOD) % MOD;
            }
        }

        for(int j = 1; j <= k; j++){
            temp[j]+=temp[j-1];
            temp[j] %= MOD;
        }
        dp=temp;
    }

    ll ans = 0;
    for(int i = 1; i <= k; i++) {
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans;
}

// 　∧　　 ∧
//  
// ↙( ◕ ‿‿ ◕ )↘