#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int n;
		cin >> n;
		bool flag = true;
		vector<string> v;
		for (int i = 0; i < n; ++i) {
			string s; cin >> s;
			v.push_back(s);
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < n-1; ++i) {
			string tmp = v[i+1].substr(0, v[i].size());
			if (v[i] == tmp) {
				flag = false;
				break;
			}
		}

		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}