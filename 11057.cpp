#include<iostream>  
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

int dp[1005][10];

int main(void)
{
	int n;
	cin >> n;

	int sum = 0;
	
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;	
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][k] += dp[i-1][j];
				dp[i][k] %= 10007;
			}
			
		}
	}

	for (int i = 0; i < 10; i++) {
		sum += dp[n][i];
	}


	
	cout << sum % 10007 << endl;

	return 0;
}
