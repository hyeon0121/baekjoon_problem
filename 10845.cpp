#include <iostream>  
#include<stack>
#include<string>
#include <queue>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	queue<int> q;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s == "push") {
			int num;
			cin >> num;

			q.push(num);
		} else if (s == "pop") {
			if (q.empty()) {
				cout << "-1" << endl;
			} else {
				cout << q.front() << endl;
				q.pop();
			}
		} else if (s == "size") {
			cout << q.size() << endl;
		} else if (s == "empty") {
			if (q.empty()){
				cout << "1" << endl;
			} else {
				cout << "0" << endl;
			}
		} else if (s == "front") {
			if (q.empty()) {
				cout << "-1" << endl;
			} else {
				cout << q.front() << endl;
			}
		} else if (s == "back") {
			if (q.empty()) {
				cout << "-1" << endl;
			} else {
				int curSize = q.size();

				//현재 큐 크기 - 1 만큼 반복문을 돌리며 front를 뒤로 넣는다
				for (int j = 0; j < curSize - 1; j++)

                                 {

                                          int num = q.front();

                                          q.pop();

                                          q.push(num);

                                 }

                                 //반복문 수행 후 front는 back

                                 int num = q.front();

                                 q.pop();

                                 cout << num << endl;

                                 //원상 복귀

                                 q.push(num);
                               
			}
		}

	}

	return 0;
}