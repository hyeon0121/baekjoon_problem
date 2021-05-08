#include <iostream>
#include <vector>

using namespace std;

char map[501][501];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
vector<pair<int,int>> wolf;
int main () {
    int r,c;

    cin >> r >> c;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 'W') {
                wolf.push_back({i,j});
            }
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (map[i][j] == '.') {
                map[i][j] = 'D';
            }
        }
    }

    bool flag = true;

    for (int i = 0; i < wolf.size(); ++i) {
        for (int k = 0; k < 4; k++) {
            int nx = wolf[i].first + dx[k];
            int ny = wolf[i].second + dy[k];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (map[nx][ny] == 'S') {
                flag = false;
                break;
            }
        }

        if (!flag) break;
    }
    
    if (flag) {
        cout << 1 << '\n';
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << map[i][j];
            }
            cout << '\n';
        }
    } else {
        cout << 0;
    }
    

    return 0;
}