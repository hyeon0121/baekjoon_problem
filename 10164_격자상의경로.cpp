#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int dp[16][16];
int n,m,k;
int main() {
    cin >> n >> m >> k;

    int x = n;
    int y = m;

    dp[0][1] = 1;

    if (k > 0) {
        x = k % m == 0 ? k/m : (k/m) +1;
        y = k % m == 0 ? m : k % m;

        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        for (int i = x; i <= n; ++i) {
            for (int j = y; j <= m; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
         
    } else {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    cout << dp[n][m];
}