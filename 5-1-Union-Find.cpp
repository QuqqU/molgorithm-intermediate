//https://www.acmicpc.net/problem/1717
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Unionfind {
public:
	vector<int> parent;

	Unionfind(int n) : parent(n + 1) {
		for (int i = 0; i < n + 1; i++)
			parent[i] = i;
	}

	int find(int me) {
		if (me == parent[me]) return me;
		return parent[me] = find(parent[me]);
	}

	void merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return;
		parent[a] = b;
	}
};

int main() {
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);
	Unionfind uf(n);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) uf.merge(b, c);
		else if (uf.find(b) == uf.find(c)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
