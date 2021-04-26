#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int n, d, k, c;
int susi[3001];
int arr[30001];

int main(void) {
    cin >> n >> d >> k >> c;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int cnt = 0;
    int answer = -1;
    
    for (int i = 0; i < k; ++i) {
        if (susi[arr[i]] == 0) cnt++;
        susi[arr[i]]++; 
    }

    for (int i = 0; i < n; ++i) {
        if (answer <= cnt) {
            if (susi[c] == 0) answer = cnt + 1;
            else answer = cnt;
        }
        susi[arr[i]]--;

        if (susi[arr[i]] == 0) cnt--;

        if (susi[arr[(i+k)%n]] == 0) cnt++;
        susi[arr[(i+k)%n]]++;
    }



    cout << answer;

    
    return 0;

}