#include <iostream>
#include <algorithm>

using namespace std;

int a,b,c,x,y;
int main() {
	cin >> a >> b >> c >> x >> y;

	int answer = 987654321;
	int money;
	int n = max(x,y);

	for (int i = 0; i <= n; i++) {
		money = (2*i*c);
		money += max(0, ((x-i)*a));
		money += max(0, ((y-i)*b));
			
		answer = min(answer,money);
	}

	cout << answer << '\n';
	return 0;
}