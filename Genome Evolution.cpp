#include <bits/stdc++.h>
using namespace std;

struct VecHash {
	size_t operator()(const vector<int>& v) const {
		size_t h = 0;
		for (int x : v) {
			h ^= hash<int>()(x) + 0x9e3779b9 + (h << 6) + (h >> 2);
		}
		return h;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		vector<vector<int>> fA(n + 1, vector<int>(n + 1, 0));
		vector<vector<int>> fB(n + 1, vector<int>(n + 1, 0));

		for (int i = 0; i < n; i++) {
			fA[i + 1] = fA[i];
			fB[i + 1] = fB[i];
			fA[i + 1][a[i]]+=1;
			fB[i + 1][b[i]]+=1;
		}

		int cnt = 0;
		unordered_map<vector<int>, int, VecHash> hashMap;

		for (int len = 2; len <= n; len++) {
			hashMap.clear();
			for (int i = 0; i + len <= n; i++) {
				vector<int> K(n + 4);
				for (int k = 1; k <= n; k++) {
					K[k] = fA[i + len][k] - fA[i][k];
				}
				hashMap[K]+=1;
			}

			for (int i = 0; i + len <= n; i++) {
				vector<int> key(n + 1);
				for (int k = 1; k <= n; k++) {
					key[k] = fB[i + len][k] - fB[i][k];
				}
				if (hashMap.count(key)) {
					cnt += hashMap[key];
				}
			}
		}

		cout << cnt << '\n';
	}
}