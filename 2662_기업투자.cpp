#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[302][22];
int arr[302][22];
int path[302][22];
int n,m;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (arr[i][j] < dp[i][j-1]) {
                p[i][j] = j-1;
            }
            int max = max(arr[i][j], dp[i][j-1]);
            for (int k = 1; k < i; ++k) {
                int tmp = dp[k][j-1] + arr[i-k][j];
                if (max < tmp) {
                    max = tmp;
                    p[i][j] = i;
                }
            }

            dp[i][j] = max;
        }
    }

    cout << dp[n][m] << "\n";



    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cout << dp[i][j] << ",";
        }
        cout << endl;
    }

}
