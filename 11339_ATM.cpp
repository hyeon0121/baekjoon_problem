#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[1001];
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	sort(arr, arr+n);

	int sum = 0, tmp = 0;

	for (int i = 0; i < n; ++i) {
		tmp += arr[i];
		sum += tmp;
	}

	cout << sum;


	return 0;
}