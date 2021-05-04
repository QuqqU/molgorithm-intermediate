#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> intii;
typedef pair<ii, int> iiint;
typedef long long int ll;

int item[105];
vector<ii> edge[105];
vector<int> dist(105, 999999999);
priority_queue<ii, vector<ii>, greater<ii>> q;

int main() {
	int n, m, r; scanf("%d %d %d", &n, &m, &r);
	for (int i = 1; i <= n; i++) scanf("%d", item + i);
	for (int i = 0; i < r; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back(ii(c, b));	
		edge[b].push_back(ii(c, a));
	}
	int ans = -1;
	
	for (int i = 1; i <= n; i++) {
		dist[i] = 0;
		q.push(ii(dist[i],i));
		while (!q.empty()) {
			int curr = q.top().second;
			int currdist = q.top().first;
			q.pop();
			if (currdist > dist[curr]) continue;

			for (ii next : edge[curr]) {
				int nextdist = dist[curr] + next.first;
				if (dist[next.second] > nextdist) {
					dist[next.second] = nextdist;
					q.push(ii(dist[next.second], next.second));
				}
			}
		}

		int rlt = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] <= m) rlt += item[i];
		}
		ans = max(ans, rlt);

		fill(dist.begin(), dist.end() ,999999999);
	}
	printf("%d\n", ans);

	
	return 0;
}
