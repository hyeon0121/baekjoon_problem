#include <string>
#include <iostream>
 
using namespace std;
 
int main() {
    string words;
    getline(cin, words);
   
    int ans = 0;
    if (words[0] != ' ') ans++;

    for (int i = 1; i < words.size(); i++) {
        if (words[i] != ' ' && words[i-1] == ' ') ans++;    
    }
    
    cout << ans;

    return 0;
}
