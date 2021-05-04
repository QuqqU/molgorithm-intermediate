// https://www.acmicpc.net/problem/2252
// Topological Sort using BFS

#include <bits/stdc++.h>
#define FASTIO                  \
    cin.sync_with_stdio(false); \
    cin.tie(0);
using namespace std;

int arr[1'005];
int dp[1'005];

int main() {
    FASTIO;

    int n, m; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
            if(arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);

    cout << *max_element(dp, dp + n) + 1;

    return 0;
}
