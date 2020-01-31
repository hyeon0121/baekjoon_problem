#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int MAX = 8;

int lab[MAX][MAX];
int tmp[MAX][MAX];

vector<pair<int, int>> location = {{0,1},{0,-1},{1,0},{-1,0}};

int n, m;

void BFS() {
	int afterWall[MAX][MAX];

	for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		afterWall[i][j] = tmp[i][j];
    	}
    	
    }

	int queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (afterWall[i][j] == 2) {
    			q.push(make_pair(i,j));
    		}
    	}
    	
    }

    while(!q.empty()) {
    	int x = q.front().second;
    	int y = q.front().first;
    	q.pop();

    	for (int i = 0; i < 4; i++) {
    		
    	}


    }
}
void makeWall(int cnt) {
	if (cnt == 3) {
		BFS();
		return;
	}

	for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (tmp[i][j] == 0) {
    			tmp[i][j] = 1;
    			makeWall(cnt + 1);
    			tmp[i][j] = 0;
    		}
    	}
    	
    }
}
int main(void) {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> lab[i][j];

    	}
    	
    }

   	for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if(lab[i][j] == 0) {
    			for (int k = 0; k < n; k++){
    				for (int l = 0; l < m; l++){
    					tmp[k][l] = lab[k][l];
    				}
    			}
    		}

    		tmp[i][j] = 1;
    		makeWall(1);
    		tmp[i][j] = 0;
    	}	
    }

	return 0;
}