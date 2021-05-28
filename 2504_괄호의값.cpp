#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main () {
    string str;
    cin >> str;

    int answer = 0;

    stack<char> s;

    int tmp = 1;

    for (int i = 0; i < str.size(); ++i) {
        if (str[i]=='(') {
            tmp *= 2;
            s.push(str[i]);
        } else if (str[i]=='[') {
            tmp *= 3;
            s.push(str[i]);
        } else if (str[i] == ')') {
            if (s.empty() || s.top() != '(') {
                answer = 0;
                break;
            } 

            if (str[i-1] == '(') answer += tmp;
            s.pop();
            tmp /= 2;

        } else if (str[i] == ']') {
            if (s.empty() || s.top() != '[') {
                answer = 0;
                break;
            } 

            if (str[i-1] == '[') answer += tmp;
            s.pop();
            tmp /= 3;
        }
    }

    if (!s.empty()) answer = 0;

    cout << answer;


    return 0;
}