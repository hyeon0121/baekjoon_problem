#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int map[13][13];
vector<int> state[13][13]; 
struct S { int y, x, d; };
S h[11];
int n,k;
int a, b, c;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1}

void move(int k) {
    for (int i = 0; i < n; i++) {
        int a = h[i].y;
        int b = h[i].x;
        int c = h[i].d;

        if (c == 1) {
            /* code */
        }

        if(state[a][b].size() >= 4) break;
    }
}

int main() {
    cin >> n >> k;

    stack<int> s;
    int row, col, dir;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }     
    }

    for (int i = 0; i < k; i++) {
        int y,x,d;
        cin >> y >> x >> d;

        y--;
        x--;

        h[i] = {y, x, d};
        state[y][x].push_back(i+1);

    }

    int cnt = 0;

    while(1) {
        if (cnt > 1000) {
            cnt = -1;
            break;
        }

        move();
        
    }

    cout << cnt;

    return 0;
}












