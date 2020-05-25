#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}

	return a.size() < b.size();
}
int main() {
	int n;
	cin >> n;

	vector<string> v;

	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), cmp);

	string tmp = v[0];
	cout << tmp << endl;

	for (int i = 1; i < n; ++i) {
		if (v[i] == tmp) {
			continue;
		}

		cout << v[i] << endl;
		tmp = v[i];
	}

	return 0;
}