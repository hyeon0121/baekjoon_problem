#include<iostream>
#include<algorithm>

using namespace std;

int dp[501][501];
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> dp[i][j];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] += dp[i-1][j];
			} else if (j == i) {
				dp[i][j] += dp[i-1][j-1];
			} else {
				dp[i][j] += max(dp[i-1][j-1],dp[i-1][j]);
			}
			
		}
	}

	int answer = 0;
	for (int i = 0; i < n; ++i) {
		if (dp[n-1][i] > answer) answer = dp[n-1][i];
	}

	cout << answer;

}