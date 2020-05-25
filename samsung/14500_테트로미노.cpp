#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n,m;
int arr[501][501];
bool visited[501][501];
int answer = -1;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void dfs(int x, int y, int val, int depth) {
	if (depth == 4) {
		if (answer < val) {
			answer = val;
		}
		return;
	}


	for (int i = 0; i < 4; ++i) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				dfs(nx, ny, val + arr[nx][ny], depth+1);
				visited[nx][ny] = false;
			}
		}


	}
}

int rotateTetro(int i, int j) {
	int sum = 0;
	// ㅜ
	if (i+1 < n && j+2 < m) {
		int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1];
		answer = max(answer, sum);
	}
	// ㅗ
	if (i-1 >= 0 && j+2 < m) {
		int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i-1][j+1];
		answer = max(answer, sum);
	}
	// ㅏ
	if (i+2 < n && j+1 < m) {
		int sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j+1];
		answer = max(answer, sum);
	}
	// ㅓ
	if (i+2 < n && j-1 >= 0) {
		int sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j-1];
		answer = max(answer, sum);
	}

}

int main() {
	cin >> n >> m;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visited[i][j] = true;
			dfs(i,j,arr[i][j],1);
			visited[i][j] = false;
			rotateTetro(i,j);
		}
	}

	cout << answer << "\n";

	return 0;
}