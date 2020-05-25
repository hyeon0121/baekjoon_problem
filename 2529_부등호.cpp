#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool visited[10];
char eq[10];
int n;
string tmp;
string max_num = "-1";
string min_num = "9999999999";

void dfs(int num, int idx) {
    if (idx == n) {
        max_num = max(max_num, tmp);
        min_num = min(min_num, tmp);

        return;
    }

    if (eq[idx] == '<') {
        for (int i = num+1; i <= 9; i++) {
            if (!visited[i]) {
                tmp += to_string(i);
                visited[i] = true;
                dfs(i, idx+1);
                visited[i] = false;
                tmp.pop_back();
            }
           
        }

    } else if (eq[idx] == '>') {
        for (int i = num-1; i >= 0; i--) {
            if (!visited[i]) {
                tmp += to_string(i);
                visited[i] = true;
                dfs(i, idx+1);
                visited[i] = false;
                tmp.pop_back();
            }
           
        }

    }
} 

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> eq[i];
    }

    tmp = "";

    for (int i = 0; i <= 9; i++) {
        tmp += to_string(i);
        visited[i] = true;
        dfs(i, 0);
        visited[i] = false;
        tmp.pop_back();

    }

    cout << max_num << '\n';
    cout << min_num;


    return 0;
}