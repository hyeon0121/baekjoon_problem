#include <iostream>  
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	
	int n;

	cin >> n;	

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int ans = 0;

	sort(v.begin(), v.end());

	do {
		int tmp = 0;
		for (int i = 0; i < n - 1; i++) {
			tmp += abs(v[i] - v[i+1]);
		}

		ans = max(tmp, ans);

	} while(next_permutation(v.begin(), v.end()));
	
	cout << ans << endl;

	return 0;
}