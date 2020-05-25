#include <string>
#include <vector>
#include <iostream>

using namespace std;

int r,c,t;
int room[51][51];
vector<int> gonggi;

vector<vector<int>> dir = {{1,0}, {-1,0}, {0,-1}, {0,1}};

void mise() {
    int tmp[51][51];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tmp[i][j] = room[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (tmp[i][j] > 0) {
                int cnt = 0;
                int amount = tmp[i][j] / 5;

                for (int k = 0; k < 4; k++) {
                    int x = dir[k][0] + j;
                    int y = dir[k][1] + i;
                    if (y < r && x < c && y >= 0 && x >= 0) {
                        if (tmp[y][x] >= 0) {
                            cnt++;
                            room[y][x] += amount;
                        }
                    }
                }

                room[i][j] -= amount * cnt;
            } 
        }
    }
}

void clean() {
    int idx = gonggi[0];

    // 공청 위 세로 : 아래로 땡겨주기
    for (int i = idx - 1; i > 0; i--) {
        room[i][0] = room[i-1][0];
    }
    // 공청 위 가로 : 왼쪽으로 땡겨주기
    for (int i = 0; i < c - 1; i++) {
        room[0][i] = room[0][i+1];
    }
    // 공청 반대 세로 : 위로 땡겨주기
    for (int i = 0; i < idx; i++) {
        room[i][c-1] = room[i+1][c-1];
    }
    // 공청 오른쪽 가로 : 오른쪽으로 땡겨주기
    for (int i = c-1; i > 1; i--) {
        room[idx][i] = room[idx][i-1];
    }
    room[idx][1] = 0;   

    idx = gonggi[1];

    // 공청 아래 세로
    for (int i = idx + 1; i < r - 1; i++) {
        room[i][0] = room[i+1][0];
    }
    // 공청 아래 가로
    for (int i = 0; i < c - 1; i++) {
        room[r-1][i] = room[r-1][i+1];
    }
    // 공청 반대 세로
    for (int i = r-1; i >= idx; i--) {
        room[i][c-1] = room[i-1][c-1];
    }
    // 공청 오른쪽 가로
    for (int i = c-1; i > 1; i--) {
        room[idx][i] = room[idx][i-1];
    }
    room[idx][1] = 0;


}

int main() {
    cin >> r >> c >> t;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> room[i][j];
            if (room[i][j] == -1) {
                gonggi.push_back(i);
            }
        }
    }

    for (int i = 0; i < t; i++) {
        mise();
        clean();
    }

    int answer = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(room[i][j] > 0) {
                answer += room[i][j];
            }
        }
        
    }

    cout << answer;

    return 0;


}