#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, k;
int answer;
vector<string> word;
bool alpha[27];

void dfs(int idx, int cnt) {
	if (cnt == k) {
		int total = 0;
		for (int i = 0; i < word.size(); ++i){
			bool flag = true;

			for (int j = 0; j < word[i].size(); ++j){
				if (!alpha[word[i][j] - 'a']) {
					flag = false;
					break;
				}
			}

			if (flag) {
				total++;
			}
			
		}

		if (answer < total) {
			answer = total;
		}



		return;
	}

	for (int i = idx; i < 26; ++i) {
		if (!alpha[i]) {
			alpha[i] = true;
			dfs(i,cnt+1);
			alpha[i] = false;
		}
	}
}
int main() {
	cin >> n >> k;
	k -= 5;

	answer = 0;

	if (k < 0) {
		cout << 0;
		return 0;
	}

	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;

		string w = s.substr(4, s.size()-8);
		word.push_back(w);
	}

	alpha['a'-'a'] = true;
	alpha['n'-'a'] = true;
	alpha['t'-'a'] = true;
	alpha['i'-'a'] = true;
	alpha['c'-'a'] = true;

	dfs(0,0);

	cout << asnwer;
	
	return 0;
}