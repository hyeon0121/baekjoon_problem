#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string chess[50];
string whiteFirst[8] = {
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"}
};
string blackFirst[8] = {
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"}    
};

int countWhiteFirst(int y, int x) {
    int cnt = 0;

    for (int i = y; i < y+8; i++) {
        string wf = whiteFirst[i-y];
        string tmp = chess[i];

        for (int j = x; j < x+8; j++) {
            if (wf[j-x] != tmp[j]) {
                cnt++;
            }
        }
    }

    return cnt;

}

int countBlackFirst(int y, int x) {
    int cnt = 0;

    for (int i = y; i < y+8; i++) {
        string bf = blackFirst[i-y];
        string tmp = chess[i];

        for (int j = x; j < x+8; j++) {
            if (bf[j-x] != tmp[j]) {
                cnt++;
            }
        }
    }

    return cnt;
}

int main(void) {
    int x,y;
    cin >> x >> y;

    int answer = 9999999;

    for (int i = 0; i < x; i++) {
        cin >> chess[i];
    }

    for (int i = 0; i + 7 < x; i++) {
        for (int j = 0; j + 7 < y; j++) {
            answer = min(answer, min(countWhiteFirst(i,j), countBlackFirst(i,j)));
        }
    }

    cout << answer << endl;

    return 0;

}