#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
const int MAX = 100;

#define pi pair<int, int>

int arr[100][100];
int main() {
    int r,c,k;
    cin >> r >> c >> k;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    int row = 3;
    int col = 3;
    int size;

    while(1) {
        if (arr[r-1][c-1] == k) {
            break;
        } 

        cnt++;

        if (cnt > MAX) {
            cnt = -1;
            break;
        }

        // R 연산
        if (row >= col) {
            size = 0;

            for (int i = 0; i < row; i++) {
                set<int> s;
                multiset<int> ms;
                priority_queue<pi, vector<pi>, greater<pi>> pq;

                for (int j = 0; j < col; j++) {
                    int num = arr[i][j];
                    if (num == 0) continue;

                    s.insert(num);
                    ms.insert(num);

                    arr[i][j] = 0;

                }

                for (auto it = s.begin(); it != s.end(); it++) {
                    pq.push(make_pair(ms.count(*it), (*it)));
                }

                int idx = 0;
                int ss = pq.size() * 2;
                size = max(size, ss);

                while(!pq.empty()) {
                    pi top = pq.top();
                    pq.pop();

                    arr[i][idx++] = top.second;
                    arr[i][idx++] = top.first;

                    if (idx == MAX) break;
                    
                }

            }

            col = size;

        } 

        // C 연산
        else {
            size = 0;

            for (int i = 0; i < col; i++) {
                set<int> s;
                multiset<int> ms;
                priority_queue<pi, vector<pi>, greater<pi>> pq;

                for (int j = 0; j < row; j++) {
                    int num = arr[j][i];
                    if (num == 0) continue;

                    s.insert(num);
                    ms.insert(num);

                    arr[j][i] = 0;
                }

                for (auto it = s.begin(); it != s.end(); it++) {
                    pq.push(make_pair(ms.count(*it), (*it)));
                }

                int idx = 0;
                int ss = pq.size() * 2;
                size = max(size, ss);

                while(!pq.empty()) {
                    pi top = pq.top();
                    pq.pop();

                    arr[idx++][i] = top.second; 
                    arr[idx++][i] = top.first;

                    if (idx == MAX) break;
                    
                }

            }

            row = size;

        }

    }

    cout << cnt;
    
   
    return 0;
}