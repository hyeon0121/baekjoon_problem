#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int map[21][21];
int fish[7];
int n;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

struct Shark {
	int x,y,size,time;
};

struct Fish {
	int x,y,d;
};

vector<Fish> fish[8];
int main() {
	cin >> n;
	int x,y;
	Shark shark;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];

			if (map[i][j] == 9) {
				shark.x = i;
				shark.y = j;
				shark.size = 2;
				shark.time = 0;
			}
		}
	}

	answer = 0;
	int nx,ny;
	int size = 2;
	while(1) {
		for (int i = 0; i < 4; ++i) {
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			if (map[nx][ny] <= size) {

			}
		}
	}

	cout << answer;

	return 0;
}