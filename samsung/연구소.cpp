#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
int n,m;
int lab[8][8];
int tmp[8][8];
vector<int> answer;

vector<vector<int>> dir = {{1,0}, {-1,0}, {0,-1}, {0,1}};

void bfs() {
    int afterwall[8][8];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            afterwall[i][j] = tmp[i][j];
        }
    }

    queue<pair<int,int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (afterwall[i][j] == 2) { 
                q.push(make_pair(i,j));
            }
        }
    }

    while(!q.empty()) {
        pair<int, int> top = q.top();
        q.pop();

        int y = top.first;
        int x = top.second;

        for (int i = 0; i < 4; i++) {
            int yy = y + vector[i].first;
            int xx = x + vector[i].second;

            if (yy < n && xx < m) {
                if (afterwall[yy][xx] == 0) {
                    afterwall[yy][xx] = 2;
                    q.push(make_pair(yy,xx));
                }
            }
            
        } 
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (afterwall[i][j] == 0) { 
                cnt++;
            }
        }
    }

    answer.push_back(cnt);

}

void makewall(int cnt) {
    if (cnt == 3) {
        bfs();
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmp[i][j] == 0) {
                tmp[i][j] = 1;
                makewall(cnt+1);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lab[i][j] == 0) {
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < m; l++) {
                        tmp[k][l] = lab[k][l];
                    }
                }
            }

            tmp[i][j] = 1;
            makewall(1);
            tmp[i][j] = 0;

        }
    }

    int mx = *max_element(answer.begin(), answer.end());

    cout << mx;
      
    return 0;
    
}