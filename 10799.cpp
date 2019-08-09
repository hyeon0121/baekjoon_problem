#include <iostream>  
#include<stack>
#include<string>

using namespace std;

int main(void)
{
	string s;

	cin >> s;

	int ans = 0;
	int pipe = 0;
	char prev;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			pipe++; 
		} else {
			pipe--;
			if (prev == '(') {
				ans += pipe;
			} else {
				ans++;
			}
		}

		prev = s[i];
	}

	cout << ans << endl;

	return 0;
}