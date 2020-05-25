#include<iostream>
#include<vector>

using namespace std;

int n;
int dx[] = {0,1,1};
int dy[] = {1,0,1};
int answer;
int map[17][17];

void solve(int x, int y, int pipe) {
	if (x == n-1 && y == n-1) {
		answer++;
		return;
	}

	for (int i = 0; i < 3; ++i) {
		if (i+pipe == 1) continue;
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= n || ny >= n || map[nx][ny] == 1) continue;
		if (i == 2 && (map[x][y+1] || map[x+1][y])) continue;
		solve(nx,ny,i); 
	}
}

int main() {
	cin >> n;
	answer = 0;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}

	solve(0,1,0);

	cout << answer;

	return 0;
}