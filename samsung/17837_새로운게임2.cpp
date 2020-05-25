#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,k;
int map[13][13];
vector<int> state[13][13];
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};
int turn[] = {0,2,1,4,3};
struct Horse {
	int x, y, d;
};
Horse h[11];

bool checkDir(int nx, int ny) {
	if (map[nx][ny] == 2 || nx < 0 || ny < 0 || nx >= n || ny >= n) {
		return false;
	}

	return true;
}
int main() {
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < k; ++i) {
		int x, y, d;
		cin >> x >> y >> d;

		x--;
		y--;

		h[i].x = x;
		h[i].y = y;
		h[i].d = d;

		state[x][y].push_back(i);
	}

	int cnt = 1;
	while(1) {
		if (cnt > 1000) {
			cnt = -1;
			break;
		}

		int x,y,d;
		int nx,ny;
		bool flag = false;
		for (int i = 0; i < k; ++i) {
			x = h[i].x;
			y = h[i].y;
			d = h[i].d;

			nx = x + dx[d];
			ny = y + dy[d];

			if (!checkDir(nx, ny)) {
				h[i].d = turn[d];
				if (!checkDir(nx, ny)) continue;
				nx = x + dx[d];
				ny = y + dy[d];
			} 

			// 해당 인덱스 찾기
			int idx;
			for (int j = 0; j < state[nx][ny].size(); ++j) {
				if (state[nx][ny][j] == i) {
					idx = j;
				}
			}

			if (map[nx][ny] == 0) {
				for (int j = idx; j < state[nx][ny].size(); ++j) {
					state[nx][ny].push_back(state[x][y][j]);
					h[state[x][y][j]].x = nx;
					h[state[x][y][j]].y = ny;
				}
			
			} else if (map[nx][ny] == 1) {
				for (int j = state[nx][ny].size()-1; j >= idx; j--) {
					state[nx][ny].push_back(state[x][y][j]);
					h[state[x][y][j]].x = nx;
					h[state[x][y][j]].y = ny;
				}
			}

			for (int j = idx; j < state[x][y].size(); ++j) {
				state[x][y].pop_back();
			}

			cout << state[nx][ny].size() << endl;
			
			if (state[nx][ny].size() >= 4) {
				flag = true;
				break;
			}

		}

		if (flag) break;	
		cnt++;
	}

	cout << cnt;

	return 0;
}