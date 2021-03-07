#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> child[51];
int root;
int rm;
int visited[51];

void bfs() {
    queue<int> q;
    q.push(root);
    visited[root] = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < child[node].size(); ++i) {
            int num = child[node][i];
            if (num == rm || visited[num] > 0) continue;

            q.push(num);
            visited[node]++;
            visited[num] = 1;
        }
    }
   

}
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (x == -1) root = i;
        else {
            child[x].push_back(i);
        }
        
    }

    cin >> rm;
    cnt = 0;

    if (rm == root) {
        cout << 0;
    } else {
        bfs();
        int res = 0;
        for (int i = 0; i < n; i++) 
            if (visited[i] == 1)
                res++;
        
        cout << res;
    }


    return 0;
}