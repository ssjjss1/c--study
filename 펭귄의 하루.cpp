#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
char d[1004][1004];
int visitedS[1004][1004], visitedF[1004][1004];
int n, m, sx, sy, hx, hy;

void bfsS() {
	queue<pair<int, int>> q;
	fill(&visitedS[0][0], &visitedS[0][0] + 1004 * 1004, -1);
	q.push({sx, sy});
	visitedS[sx][sy] = 0;

	while (!q.empty()) {
		auto [cx, cy] = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if (d[nx][ny] == 'D' || visitedS[nx][ny] != -1) continue;
			visitedS[nx][ny] = visitedS[cx][cy] + 1;
			q.push({nx, ny});
		}
	}
}

void bfsF() {
	queue<pair<int, int>> q;
	fill(&visitedF[0][0], &visitedF[0][0] + 1004 * 1004, -1);

	q.push({hx, hy});
	visitedF[hx][hy]=0;

	while (!q.empty()) {
		auto [cx, cy] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if (d[nx][ny] == 'D' || visitedF[nx][ny] != -1) continue;
			visitedF[nx][ny] = visitedF[cx][cy] + 1;
			q.push({nx, ny});
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> d[i][j];
			if (d[i][j] == 'S') sx = i, sy = j;
			if (d[i][j] == 'H') hx = i, hy = j;
		}

	bfsS();
	bfsF();

	int ans = 1e9;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (visitedF[i][j] != -1 && visitedS[i][j] != -1 && d[i][j]=='F') {
				ans = min(ans, visitedF[i][j] + visitedS[i][j]);
			}

	if (ans == 1e9) cout << -1;
	else cout << ans;
}