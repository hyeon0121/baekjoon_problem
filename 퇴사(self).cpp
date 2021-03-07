#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[16];
int t[16];
int p[16];

int main() {
   
    int n;
    int mx = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> p[i];
    }

    /* 셀프 */
    for (int i = n; i >= 1; i--) {
        if (i + t[i] > n+1) {
             dp[i] = dp[i+1];
             continue;
        }

        dp[i] = dp[i+t[i]] + p[i];

        if (dp[i] > mx) {
            mx = dp[i];
        } else {
            dp[i] = mx;
        }
    }

    cout << mx;

    /* 참고 */
    for (int i = n; i >= 1; i--) {
        if (i + t[i] > n+1) {
             dp[i] = dp[i+1];
             continue;
        }

        dp[i] = max(dp[i+t[i]] + p[i], dp[i+1]);
        
    }

    cout << dp[1];

    return 0;
}