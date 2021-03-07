#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[11];
bool visited[11];
int ans[11];
int n;

void dfs(int cnt) {
    if (cnt == n+1) {
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int left = 0;
            for (int j = 1; j < cnt; j++) {
                if (ans[j] > i) left++;
            }

            if (arr[i] == left) {
                visited[i] = true;
                ans[cnt] = i;
                dfs(cnt+1);
            }
           
        }
    }

}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
       cin >> arr[i];
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
       cout << ans[i] << " ";
    }

    return 0;
}