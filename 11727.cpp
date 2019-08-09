#include <iostream>  
#include<stack>
#include<string>

using namespace std;

int dp[1001] = {1, 1, 3};

int DP(int n) {
	if (n <= 1){
		return dp[n];
	} else if (n == 2) {
		return dp[n];
	} else {
		for (int i = 3; i <= n; i++)
		{
			dp[i] = dp[i-1] + 2 * dp[i-2];
			dp[i] %= 10007;
		}

		return dp[n];
	}

}

int main(void)
{
	int n;

	cin >> n;
	

	cout << DP(n) << endl;

	return 0;
}

