#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int n,m,k;
int main() {
    int answer = 987654321;

    cin >> n >> k;

    deque<int> dq;
    int x;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x == 1) dq.push_back(i);

        if (dq.size() == k) {
            answer = min(answer, dq.back() - dq.front()+1);
            dq.pop_front();
        }
    }

    if (answer == 987654321) answer = -1;

    cout << answer;
}