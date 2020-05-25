#include <iostream>

using namespace std;

int n,m;
char map[1001][1001];
int answer;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void solve(int x, int y, int time) {
	int nx,ny;
	int cnt = 0;
	bool flag = false;
	for (int i = 0; i < 4; ++i) {
		nx = dx[i] + x;
		ny = dy[i] + y;
		if (map[nx][ny] == '.') {
			flag = true;
			break;
		}

		cnt++;
	}

	if (flag) {
		solve(time+1);
	}
	if (cnt == 4) {
		return;
	}

	


}

int fire() {

}
int main() {
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> m;

		bool flag = true;
		string res = "IMPOSSIBLE";
		answer = 987654321;

		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> map[i][j];

				if (map[i][j] == '@') {
					x = i;
					y = j;
				}
			}
		}

		solve(x,y,0);
		
	}
	return 0;
}