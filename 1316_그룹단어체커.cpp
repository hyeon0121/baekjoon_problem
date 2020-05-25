#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    int answer = 0;
    vector<string> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for (int i = 0; i < n; ++i) {
        string s = v[i];
        vector<bool> visited(26,0);

        visited[s[0]-'a'] = true;
        char tmp = s[0];

        bool flag = true;

        for (int j = 1; j < s.size(); ++j) {
            if (tmp != s[j]) {
                if (visited[s[j]-'a']) {
                    flag = false;
                    break;
                } else {
                    visited[s[j]-'a'] = true;
                    tmp = s[j];
                }
            }
        }

        if (flag) answer++;

    }

    cout << answer;

    return 0;
}
 
