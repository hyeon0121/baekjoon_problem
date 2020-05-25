#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[27];

int main() {
    cin >> n;
    int answer = 0;

    vector<string> v;

    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < n; ++i) {
        string s = v[i];
        int pow = 1;

        for (int j = s.size()-1; j >= 0; j--) {
            int tmp = s[j] - 'A';
            arr[tmp] += pow;

            pow *= 10;
        }
    }

    sort(arr, arr+27, greater<int>());

    int num = 9;
    for (int i = 0; i < 27; ++i) {
        if (arr[i] == 0) continue;

        answer += arr[i] * num;
        num--;
    }

    cout << answer;

    return 0;
}