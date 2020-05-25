#include <iostream>
using namespace std;

int main() {
	int answer = 0;

	int a, b;
	cin >> a >> b;
	for (int i = 0; i < 3; ++i) {
		int a1, b2;
		cin >> a1 >> b2;

		int cnt = b - a1 + b2;

		if (b < cnt) answer = cnt;

		b = cnt;
	}

	cout << answer;

	return 0;

}