#include <iostream>  
#include<stack>
#include<string>

using namespace std;

int dp[11] = {0, 1, 2, 4};

int DP(int n) {
	if (n <= 3){
		return dp[n];
	} else {
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		}

		return dp[n];
	}

}

int main(void)
{
	int t;

	cin >> t;
	

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << DP(n) << endl;
	}
	

	return 0;
}
