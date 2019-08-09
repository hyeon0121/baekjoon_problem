#include <iostream>  
#include<stack>
#include<string>

using namespace std;

int main(void)
{
	int size;
	cin >> size;

	stack<char> st;

	for (int i = 0; i < size; i++) {
	 	string str;
	 	cin >> str;

	 	for (int j = 0; j < str.length(); j++) {
	 		if (str[j] == '(' || st.empty()){
	 			st.push(str[j]);

	 		} else if (st.top() == '(') {
	 			st.pop();
	 		}
	 	}

	 	if (st.empty()) {
	 		cout << "YES" << endl;
	 	} else {
	 		cout << "NO" << endl;
	 	}

	 	// 스택 초기화
	 	while (!st.empty()) {
	 		st.pop();
	 	}
	 }

	return 0;
}