#include<iostream>
#include<deque>

using namespace std;

int n,l;
int arr[5000000];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상
    
    cin >> n >> l;
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    deque<int> dq;

    for (int i = 0; i < n; ++i){
        if (!dq.empty() && dq.front() < i-l+1) {
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] > arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
        cout << arr[dq.front()] << ' ';

    }
    
    return 0;

}

