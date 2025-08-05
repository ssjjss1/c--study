#include <bits/stdc++.h>
#define INF 200004
using namespace std;

int ans, parent[INF];
map<int, vector<pair<int, int>>> adj;
vector<int> a(INF);

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y) return false;

    if (a[x] > a[y]) swap(x, y);
    parent[y] = x;

    return a[x] == a[y];
}

void Init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    Init(n);
    ans = n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        int mn = min(a[u], a[v]);
        adj[mn].emplace_back(u, v);
    }

    for (auto it = adj.rbegin(); it != adj.rend(); it++) {
        for (auto [u, v] : it->second) {
            if (Union(u, v)) {
                ans-=1; 
            }
        }
    }

    cout << ans;
}