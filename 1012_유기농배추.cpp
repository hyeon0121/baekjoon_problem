#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int map[51][51];
bool visited[51][51];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int t,m,n,s;

void dfs(int x, int y) {
    int nx,ny;
    for (int i = 0; i < 4; ++i) {
        nx = x + dx[i];
        ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

        if (map[nx][ny] == 1 && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx,ny);
        }
    }
    
}
int main(void) {
    cin >> t;

    for (int tc = 0; tc < t; ++tc) {
        int cnt = 0;

        cin >> m >> n >> s;

        int x,y;
        for (int i = 0; i < s; ++i) {
            cin >> x >> y;

            map[y][x] = 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(map[i][j] == 1 && !visited[i][j]) {
                    visited[i][j] = true;
                    dfs(i,j);
                    cnt++;

                    
                }
            }
        }

        cout << cnt << '\n';
        
    }

    return 0;
}