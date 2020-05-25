#include<iostream>

using namespace std;

int map[21][21];
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};
int dir[] = {0,0,0,0,0,0}; // 상,하,앞,뒤,왼,오

int main() {
	int n,m,x,y,k;

	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}

	int d;
	for (int i = 0; i < k; ++i) {
		cin >> d;
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

		int tmp;
		if (d == 1) {
			tmp = dir[5];
			dir[5] = dir[0];
			dir[0] = dir[4];
			dir[4] = dir[1];
		} else if (d == 2) {
			tmp = dir[4];
			dir[4] = dir[0];
			dir[0] = dir[5];
			dir[5] = dir[1];
		} else if (d == 3) {
			tmp = dir[3]; // 뒤
			dir[3] = dir[0];
			dir[0] = dir[2];
			dir[2] = dir[1];
		} else if (d == 4) {
			tmp = dir[2]; // 앞
			dir[2] = dir[0];
			dir[0] = dir[3];
			dir[3] = dir[1];	
		}

		if (map[nx][ny] == 0) {
			dir[1] = tmp;
			map[nx][ny] = tmp;
		} else {
			dir[1] = map[nx][ny];
			map[nx][ny] = 0;
		}

		x = nx;
		y = ny;

		cout << dir[0] << "\n";

	}

	return 0;
}