// https://www.acmicpc.net/problem/2252
// Topological Sort using DFS

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> edge;
vector<bool> visited;
vector<int> topology;

void dfs(int curr) {
	visited[curr] = true;
	for (int next : edge[curr])
		if (!visited[next]) dfs(next);
	topology.push_back(curr);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	edge.resize(n + 1);
	visited.resize(n + 1, false);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
		if (!visited[i]) dfs(i);

	reverse(topology.begin(), topology.end());

	for (int cursor : topology)
		printf("%d ", cursor);

	return 0;
}
