#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, l;
    cin >> n >> l;

    vector<pair<ll, ll>> pir;
    for(int i = 0; i < n; i++) {
        ll x, y, c;
        cin >> x >> y >> c;
        ll s = x * x + y * y;
        long double dist = sqrt((long double)s);
        ll t = l - (ll)ceil(dist);
        if (t >= 0) {
            pir.push_back({t, c});
        }
    }

    sort(pir.begin(), pir.end());
    ll ans = 0, cx = 0;

    for (auto [dist, c] : pir) {
        pq.push(c);
        cx += c;
        long long sz=(ll)pq.size();
        if (sz - dist > 1) {
            cx -= pq.top();
            pq.pop();
        }
        ans = max(ans, cx);
    }

    cout << ans;
}