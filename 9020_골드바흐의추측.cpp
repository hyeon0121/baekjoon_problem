#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int tc = 0; tc < n; ++tc) {
        int num;
        cin >> num;

        int l = num/2;
        int r = num/2;

        while(1) {
            bool flag = false;
            for (int i = 2; i < num; ++i) {
                if ((i != l && l % i == 0) || (i != r && r % i == 0)) {
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                break;
            } 

            l--;
            r++;
        }

        cout << l << " " << r << '\n';

        
    }

    return 0;
}