#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, k;
int arr[100001];


int main() {
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int sum = 0;
	int l = 0;
	int r = 0;
	int answer = 987654321;
	
	while(l <= n) {
		if (sum >= k) {
			answer = min(answer, r-l);
			sum -= arr[l++];

		} else if (r == n) {
			break;
		} else {
			sum += arr[r++];
		}

	}

	if (answer == 987654321) cout << 0;
	else cout << answer;
	
	return 0;
}