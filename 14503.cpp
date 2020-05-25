#include<iostream>  
#include<string>
#include<vector>

using namespace std;

int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}}; // 북,남,동,서
int room[51][51]; 

int main(void) {
	int n, m;
	cin >> n >> m;
	
	int r, c, d;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
		}
	}

  int ans = 0;
	room[r][c] = -1; // 현재 청소기 위치 청소 
	ans++;
    
	int x, y, nd;

	while(1) {
		int cnt = 0;
		int tmp = d; // 현재 방향 복사
		bool flag = false; 

		for (int i = 0; i < 4; i++) {
			// 현재 방향에서 왼쪽 방향
			if (d == 0) d = 3;
			else d--;

			y = dir[d][0] + r;
			x = dir[d][1] + c;

			if (room[y][x] == 0) {
				flag = true;
				break;
			} 
			// 네 방향 모두 청소가 이미 되어있거나 벽인 경우
			else if (room[y][x] != 0) {
				cnt++;
			}

		}

		if (flag) {
			room[y][x] = -1;
			ans++;
		}

		if (cnt == 4) {
			d = tmp;
			y = r - dir[d][0];
			x = c - dir[d][1];
			
			// 뒤쪽 방향이 벽인 경우
			if (room[y][x] == 1) {
				break;
			}

		}

		r = y;
		c = x;

	}

	cout << ans;

	return 0;
}