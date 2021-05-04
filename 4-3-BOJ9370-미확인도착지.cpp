#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <set>
#define INF 9999999
using namespace std;
typedef pair<int, int> ii;


set<int> st;
set<ii> pass;
vector<vector<ii>> edge;
vector<int> dist;
vector<int> dist2;
vector<int> parent;
priority_queue<ii, vector<ii>, greater<ii>> pq;
vector<int> ans;

int main() {
	int testcase; scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++) {
		int n, m, t; scanf("%d %d %d", &n, &m, &t);
		edge.resize(n + 1);
		dist.resize(n + 1, INF);
		dist2.resize(n + 1, INF);
		parent.resize(n + 1, -1);
		int s, g, h; scanf("%d %d %d", &s, &g, &h);
		for (int i = 0; i < m; i++) {
			int a, b, c; scanf("%d %d %d", &a, &b, &c);
			edge[a].push_back(ii(c, b));
			edge[b].push_back(ii(c, a));
		}
		for (int i = 0; i < t; i++) {
			int x; scanf("%d", &x);
			st.insert(x);
		}


		dist[s] = 0;
		pq.push(ii(dist[s], s));
		while (!pq.empty()) {
			int curr = pq.top().second;
			int currdist = pq.top().first;
			pq.pop();
			if (dist[curr] < currdist) continue;
			for (auto next : edge[curr]) {
				int nextdist = dist[curr] + next.first;
				if (dist[next.second] > nextdist) {
					dist[next.second] = nextdist;
					pq.push(ii(dist[next.second], next.second));
					parent[next.second] = curr;
				}
			}
		}

		int bridge = dist[h] > dist[g] ? dist[h] : dist[g];
		int sv = bridge == dist[h] ? h : g;
		int p = sv;
		while (1) {
			int j = parent[p];
			if (j == -1) break;
			pass.insert(ii(p, j));
			pass.insert(ii(j, p));
			p = j;
		}

		dist2[sv] = 0;
		pq.push(ii(dist2[sv], sv));
		while (!pq.empty()) {
			int curr = pq.top().second;
			int currdist = pq.top().first;
			pq.pop();
			if (dist2[curr] < currdist) continue;
			for (auto next : edge[curr]) {
				if (pass.find(ii(curr, next.second)) != pass.end()) continue;
				int nextdist = dist2[curr] + next.first;
				if (dist2[next.second] > nextdist) {
					dist2[next.second] = nextdist;
					pq.push(ii(dist2[next.second], next.second));
				}
			}
		}

		for (int i = 1; i <= n; i++)
			if (st.count(i) && dist2[i] != -1 && dist[i] >= dist2[i] + bridge)
				ans.push_back(i);
		for (int cursor : ans)
			printf("%d ", cursor);
		puts("");


		ans.clear();
		edge.clear();
		dist.clear();
		dist2.clear();
		pass.clear();
		st.clear();
		parent.clear();
	}
	
	return 0;
}
