// https://www.acmicpc.net/problem/2252
// Topological Sort using BFS

#include <bits/stdc++.h>
#define FASTIO                  \
    cin.sync_with_stdio(false); \
    cin.tie(0);
using namespace std;

vector<int> edge[32'005];
int in[32'005];  // indegree of vertex

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        in[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) q.push(i);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        cout << curr << " ";

        for (int next : edge[curr]) {
            in[next]--;
            if (in[next] == 0) q.push(next);
        }
    }

    return 0;
}
