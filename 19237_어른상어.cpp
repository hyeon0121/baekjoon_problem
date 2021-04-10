#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int n,m,k;
int map[21][21];
int prev_smell[21][21];
int smell[21][21];
int dx[] = {0,-1,1,0,0};
int dy[] = {0,0,0,-1,1};
int prior[401][5][5];
bool die[401];
int answer;

struct Shark
{
    int x;
    int y;
    int dir;
};

int die_cnt;
Shark shark[401];

void minusSmell() {
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) {
            if (smell[i][j] > 0) {
                smell[i][j]--;
            }

            if (smell[i][j] == 0 && map[i][j] > 0) {
                map[i][j] = 0;
            }
        }
    }
}
void choiceDir(vector<Shark> v, int idx, int cur_dir) {
    for (int j = 1; j <= 4; ++j) {
        for (int i = 0; i < v.size(); ++i) {
            int x = v[i].x;
            int y = v[i].y;
            int dir = v[i].dir;

            if (prior[idx][cur_dir][j] == dir) {
                if (map[x][y] > 0 && map[x][y] != idx) {
                    die[idx] = true;
                    die_cnt++;
                    return;
                }

                map[x][y] = idx;
                smell[x][y] = k+1;

                shark[idx].x = x;
                shark[idx].y = y;
                shark[idx].dir = dir;

                return;

            }
            
        }      
    }

    
}

bool move() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            prev_smell[i][j] = smell[i][j];
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (die[i]) continue;

        int x = shark[i].x;
        int y = shark[i].y;
        int dir = shark[i].dir;

        vector<Shark> d;
        vector<Shark> my_dir;

        for (int j = 1; j <= 4; ++j) {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if (nx < 0 || ny < 0 || ny >= n || nx >= n) continue;

            // 아무 냄새가 없는 칸
            if (prev_smell[nx][ny] == 0) {
                Shark tmp = {nx,ny,j};
                d.push_back(tmp);
            } 
            // 자신의 냄새가 있는 칸
            else if (map[nx][ny] == i) {
                Shark tmp = {nx,ny,j};
                my_dir.push_back(tmp);
            }
        }

        
        // 아무 냄새없는 칸
        if (d.size() > 0) {
            choiceDir(d, i, dir);
        } 
        // 자신 냄새가 있는 방향
        else {
            choiceDir(my_dir, i, dir);
        }

        if (die_cnt == m-1) return false;
    }

    minusSmell();

    return true;
}
int main(void) {
    cin >> n >> m >> k;

    answer = -1;
    die_cnt = 0;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];

            if (map[i][j] > 0) {
                shark[map[i][j]].x = i;
                shark[map[i][j]].y = j;
                smell[i][j] = k;
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        int d;
        cin >> d;
        shark[i].dir = d;
    }


    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= 4; ++j) {
            for (int k = 1; k <= 4; ++k) {
                cin >> prior[i][j][k];
            }
            
        }
    }

    int cnt = 0;
    for (int i = 1; i <= 1000; ++i) {
        cnt++;
        bool flag = move();

        if (!flag) {
            answer = cnt;
            break;
        }
    }

    cout << answer;

    return 0;

}