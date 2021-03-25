#include <iostream>
#include <algorithm>
using namespace std;


int dp[10005][5];//1000*3

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dp[i][0] = min(dp[i - 1][1] + a, dp[i - 1][2] +a);
		dp[i][1] = min(dp[i - 1][0] + b, dp[i - 1][2] +b);
		dp[i][2] = min(dp[i - 1][0] + c, dp[i - 1][1] + c);
	}
	printf("%d\n", min(dp[n][0], min(dp[n][1], dp[n][2])));
	return 0;
}
