#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> edge[1005];
vector<bool> visited(1005, false);

void dfs(int curr) {
	visited[curr] = true;
	for(int next : edge[curr])
		if (!visited[next]) dfs(next);
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	int numC = 0;
	for(int i=1; i<=n; i++) 
		if (!visited[i]) {
			dfs(i);
			numC++;
		}
	printf("%d\n", numC);

	return 0;
}
