#include <iostream>  
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int buf[1001][1001];
bool visited[1001];
bool color[1001];

queue<int> q;

int n, m, v;

void DFS(int start) {
	cout << start << " ";

	for (int i = 1; i <= n; i++) {
		if (!visited[i] && buf[start][i]) {
			visited[i] = 1;
			DFS(i);
		}
	}
}

void BFS(int start) {
	q.push(start);
	visited[start] = 1;

	cout << start << " ";

	while(!q.empty()) {
		int top = q.front();
		q.pop();

		for (int i = 1; i <=n; i++) {
			if (!visited[i] && buf[top][i]) {
				visited[i] = 1;
				q.push(i);

				cout << i << " ";
			}
		}
	}
	
}

int main(void) {
	
	cin >> n >> m >> v;	

	for (int i = 0; i < m; i++) {
		int f, t;
		cin >> f >> t;

		buf[f][t] = 1;
		buf[t][f] = 1;
	}

	visited[v] = 1;
	DFS(v);

	cout << endl;

	memset(visited, false, sizeof(visited));

	BFS(v);

	return 0;
}