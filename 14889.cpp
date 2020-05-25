#include <string>
#include <vector>
#include <iostream>

using namespace std;

int t[21][21];
int n;
int ans = 987654321;
bool visited[21];

void dfs(int cur_mem, int cnt) {
    if (cnt == n/2) {
        vector<int> start, link;
        int s = 0, l = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) start.push_back(i);
            else link.push_back(i);
        }


        for (int i = 0; i < n/2; i++) {
            for (int j = i+1; j < n/2; j++) {
                int sx = start[i]; int sy = start[j];
                int lx = link[i]; int ly = link[j];
                s += t[sx][sy] + t[sy][sx];
                l += t[lx][ly] + t[ly][lx];
            }
        }

        ans = min(ans, abs(s-l));

        return;
    }

    for (int i = cur_mem+1; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i,cnt+1);

            visited[i] = false;
        }
    }

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t[i][j];
        }
    }

    dfs(0,0);

    cout << ans << endl;

    return 0;
}