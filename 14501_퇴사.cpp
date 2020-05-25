#include<iostream>
#include<algorithm>

using namespace std;

int t[16];
int p[16];
int dp[16];
int main() {
	int n;
	cin >> n;
	int answer = 0;

	for (int i = 0; i < n; ++i) {
		cin >> t[0] >> p[i][1];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = t[i] + i; j <= n; ++j) {
			dp[j] = max(dp[i] + p[i], dp[j]);
		}
		
	}

	cout << dp[n];

	return 0;
}