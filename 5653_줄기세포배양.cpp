#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int n,m,k;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int map[350][350][2];

#define offset 150

int main() {
	int T;
	cin>>T;
	
	for(int test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> m >> k;
		memset(map, 0, sizeof(map));
		int answer = 0;
		queue<pair<int,int>> q[11];


		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int val;
				cin >> val;
				map[i+offset][j+offset][0] = val;
				map[i+offset][j+offset][1] = val*2;

				if (val > 0) {
					q[val].push({i+offset, j+offset});
				}
				
			}
		}

		while(k--) {
			for (int i = 10; i >= 0; i--) {
				int size = q[i].size();

				for (int j = 0; j < size; ++j) {
					int x = q[i].front().first;
					int y = q[i].front().second;
					q[i].pop();

					map[x][y][1]--;

					// 번식
					if (map[x][y][0] > map[x][y][1]) {
						for (int j = 0; j < 4; ++j) {
							int nx = x + dx[j];
							int ny = y + dy[j];

							if (map[nx][ny][0] == 0) {
								map[nx][ny][0] = map[x][y][0];
								map[nx][ny][1] = map[x][y][0] * 2;
								q[i].push({nx,ny});
							}
						}
					}

					if (map[x][y][1] > 0) q[i].push({x,y});
				}
			}
		}

		int cnt = 0;
		for (int i = 10; i >= 0; i--) {
			cnt += q[i].size();
		}

		cout << "#" << test_case << " " << cnt << "\n";

	}

	return 0;
}