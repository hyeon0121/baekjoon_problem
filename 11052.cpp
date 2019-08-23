#include<iostream>  
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

int p[10001] = {0};
int d[1001] = {0};

void maxPrice(int n) {
	d[1] = p[1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], d[i-j] + p[j]);
		}		
	}
}

int main(void) {
	int t;
	cin >> t;
	
	for (int i = 1; i <= t; i++) {
		cin >> p[i];	
	}
	
	maxPrice(t);
	
	cout << d[t] << endl;

	return 0;
}
