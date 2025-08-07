#include<bits/stdc++.h>
using namespace std;

int parent[202004];
vector<int> a(202004);

int find(int x) {
	if(x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);

	if(x != y) {
		parent[x] = y;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++){
	      parent[i] = i;
	}
	
	for(int i = 1; i <= n; i++) {
	      int x;
		cin >> x;
		Union(i, x);
		a[x]=i;
	}

	int cnt = 0, ans = 0;
	vector<pair<int,int>> v;

	for(int i = 1; i < n; i++) {
		int x = find(i);
		int y = find(i + 1);

		if(x != y) {
			v.push_back({a[i], a[i + 1]});
			swap(a[i], a[i + 1]);
			Union(i, i+1);
			cnt += 1;
			ans += 1;
		}
	}

	cout << ans << " " << cnt << "\n";
	for(auto [x, y] : v) {
		cout << x << " " << y << "\n";
	}
}