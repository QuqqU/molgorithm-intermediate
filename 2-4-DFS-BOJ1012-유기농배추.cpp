#include <bits/stdc++.h>
#define FASTIO cin.sync_with_stdio(false); cin.tie(0);
#define x first
#define y second
using namespace std;
using ll = long long;
using ii = pair<int, int>;


bool bachu[55][55]; // [x][y] (x,y)에 배추가 있으면 true
bool vis[55][55]; // (x,y)를 방문했다면 true, 아직 방문하지 않았다면 false / 배추가 없는 땅은 영원히 방문 안됨
int n, m, k;

// 상하좌우를 살펴보기 위해 사용하는 도구
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void dfs(int x, int y) {
	vis[x][y] = true;

	// 다음 정점 확인
	// (x + dx[i], y + dy[i]) 가 상하좌우에 인접해 있는 다음 정점을 나타냄
	for (int i = 0; i < 4; i++) {
		// 상하좌우에 해당하는 좌표가 유효한지 확인하고,
		// 유효한 좌표라면 배추가 있는 자리인지, 방문을 했는지 확인하고
		// 방문을 안했다면 방문
		if (0 <= x + dx[i] && x + dx[i] < n
			&& 0 <= y + dy[i] && y + dy[i] < m
			&& bachu[x + dx[i]][y + dy[i]]
			&& !vis[x + dx[i]][y + dy[i]])
			dfs(x + dx[i], y + dy[i]);
	}
}

int main() {
	FASTIO;

	int T; cin >> T;
	while (T--) {

		// initialize
		memset(bachu, 0, sizeof(bachu));
		memset(vis, 0, sizeof(vis));

		cin >> n >> m >> k;
		while (k--) {
			int a, b; cin >> a >> b;
			bachu[a][b] = 1;
		}

		int cnt = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if (bachu[i][j] && !vis[i][j]) {
					dfs(i, j);
					cnt++;
				}
		cout << cnt << "\n";
	}
	

	return 0;
}
