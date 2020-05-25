// 참고 : https://j2wooooo.tistory.com/42
#include <algorithm>
#include <iostream>

using namespace std;

int t[1500002];
int p[1500002];
int dp[1500002];
int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    for (int i = n; i >= 1; i--) {
        if (i + t[i] > n+1) {
            dp[i] = dp[i+1];
        } else {
            dp[i] = max(dp[i+1], p[i] + dp[i + t[i]]);
        }
    }

    cout << dp[1];
    
    return 0;
}