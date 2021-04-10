#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int n;
int shark_size;
int map[21][21];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int cnt;
int fx,fy;

struct Fish {
    int x;
    int y;
    int dist;
};

int searchFish(int sx, int sy) {
    queue<Fish> q;
    bool visited[21][21] = {false, };

    Fish f = {sx,sy,0};
    q.push(f);
    visited[sx][sy] = true;
    int mn = 987654321;

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int dist = q.front().dist;

        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || ny >= n || nx >= n) continue;

            if (!visited[nx][ny]) {
                if (map[nx][ny] == shark_size || map[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    Fish val = {nx,ny,dist+1};
                    q.push(val);
                } else if (map[nx][ny] < shark_size) {
                    if (mn > dist+1) {
                        fx = nx;
                        fy = ny;
                        mn = dist+1;
                    } else if (mn == dist+1) {
                        if (nx < fx) {
                            fx = nx;
                            fy = ny;
                        } else if (nx == fx) {
                            if (ny < fy) {
                                fx = nx;
                                fy = ny;
                            }
                        }

                    }
                }
            }
        }
    }

    return mn;
    
}
int main(void) {
    cin >> n;

    shark_size = 2;
    int answer = 0;
    int r,c;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                r = i;
                c = j;
            } 
        }
    }
    
    map[r][c] = 0;


    while(1) {
        fx = -1;
        fy = -1;

        int dist = searchFish(r,c);

        if (fx < 0 && fy < 0) break;

        // 물고기먹음
        map[fx][fy] = 0;
        r = fx;
        c = fy;
        answer += dist;
        cnt++;

        if (shark_size == cnt) {
            shark_size++;
            cnt = 0;
        }
    }

    cout << answer;

    return 0;

}