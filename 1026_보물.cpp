#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);
	int answer = 0;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end());

	for (int i = 0; i < n; ++i) {
		answer += a[i] * b[i];
	}

	cout << answer << endl;

	return 0;
}