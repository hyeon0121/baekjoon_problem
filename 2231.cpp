#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int temp, sum;
    for (int i = 1; i < n; i++) {
        temp = i;
        sum = i;

        while(temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum == n) {
            return i;
        }
    }

    return 0;

}
int main(void) {
    int n;
    cin >> n;

    cout << solution(n) << endl;

    return 0;

}