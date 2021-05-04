// BOJ 9466 텀프로젝트

#include <bits/stdc++.h>
#define FASTIO cin.sync_with_stdio(false); cin.tie(0);
#define x first
#define y second
using namespace std;
using ll = long long;
using ii = pair<int, int>;

// 사실 outdegree = 1 이기 때문에 그냥 1차원 배열을 사용하는 것이 좋지만,
// 다른 문제들과 통일성 있는 구현을 위해 2차원 벡터을 사용합니다
// 무슨 말인지 모르겠다면, 지금은 넘어가셔도 좋습니다
vector<vector<int>> edge;
vector<int> vis;
vector<bool> fin;
int cnt; // 몇번째로 방문한 정점인가?
int ans; // 싸이클에 속해 있는 학생 수

void dfs(int curr) {
	vis[curr] = cnt++; // curr 정점 방문, curr정점이 몇번째 방문인지 기록
	for (int next : edge[curr]) {
		if (vis[next] == -1) dfs(next);
		else if (!fin[next]) ans += vis[curr] - vis[next] + 1; // 싸이클, 현재정점방문번호 - 지난정점방문번호 + 1 == 싸이클의 크기
	}
	fin[curr] = true; // 함수 종료
}

int main() {
	FASTIO;

	int T; cin >> T;
	while (T--) {

		// initialize
		ans = cnt = 0;
		edge.assign(100'005, vector<int>());
		vis.assign(100'005, -1);
		fin.assign(100'005, false);

		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			edge[i].push_back(a);
		}

		for (int i = 1; i <= n; i++)
			if (vis[i] == -1) dfs(i);

		cout << n - ans << "\n";
	}
	

	return 0;
}
