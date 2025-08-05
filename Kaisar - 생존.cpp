#include <bits/stdc++.h>
#define INF 200004
using namespace std;

vector<int> adj[INF];
int root;
vector<long long> cnt(INF, 1), temp(INF, 0);

void dfs(int cx) {
	temp[cx] = 1;
	for (auto nx : adj[cx]) {
		dfs(nx);
		cnt[cx] += temp[nx] * temp[cx] * 2LL;
		temp[cx] += temp[nx];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u;
		if (u == 0) root = i;
		else adj[u].push_back(i);
	}

	dfs(root);

	long long odd = 0, even = 0, idx = 1;
	for (long long i = 1; i <= n; i++) {
		long long a = (cnt[i] + 1) / 2;
		long long b = cnt[i] / 2;
		if (idx) odd += a * i, even += b * i;
		else odd += b * i, even += a * i;
		idx = (idx + cnt[i]) % 2;
	}
	cout << even << " " << odd;
}