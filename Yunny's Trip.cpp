#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct PH {
    size_t operator()(const pair<ll, ll>& p) const {
        return hash<ll>()(p.first) ^ (hash<ll>()(p.second) << 1);
    }
};

unordered_map<pair<ll, ll>, int, PH> ma;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, Ex, Ey;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        ma[{x, y}] = 1;
    }
    cin >> Ex >> Ey;

    ll ans = INF;

    ll dist = abs(Ex) + abs(Ey);
    if (dist <= k) ans = min(ans, dist);

    if (k < 2) {
        cout << (ans == INF ? -1 : ans);
        return 0;
    }

    for (auto &it : ma) {
        ll s = it.first.first;
        ll e = it.first.second;
        ll dist1 = abs(Ex - s) + abs(Ey - e);
        if (2 + dist1 <= k) {
            ans = min(ans, 2 + dist1);
        }
    }

    if (k >= 4) {
        for (auto &it : ma) {
            ll s = it.first.first;
            ll e = it.first.second;
            ll S = Ex - s, T = Ey - e;
            if (ma.find({S, T}) != ma.end()) {
                ans = min(ans, 4LL);
            }
        }
    }

    if (k >= 5) {
        for (auto &it : ma) {
            ll s = it.first.first;
            ll e = it.first.second;
            ll S = Ex - s, T = Ey - e;
            for (int j = 0; j < 4; j++) {
                ll nx = S + dx[j], ny = T + dy[j];
                if (ma.find({nx, ny}) != ma.end()) {
                    ans = min(ans, 5LL);
                }
            }
        }
    }

    cout << (ans == INF ? -1 : ans);
}