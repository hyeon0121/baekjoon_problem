#include<iostream>  
#include<stack>
#include<string>

using namespace std;

int arr[105];

bool findPrime(int n) {
	if (n < 2) {
		return false;
	} 

	for (int i = 2; i < n; i++) {
		if (n%i == 0) {
			return false;
		}
	}

	return true;
}

int main(void)
{

	int n;

	cin >> n;

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (findPrime(arr[i])){
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}