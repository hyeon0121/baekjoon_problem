#include<iostream>  
#include<stack>
#include<string>
#include <vector>
#include <algorithm>

using namespace std;

const int E = 15;
const int S = 28;
const int M = 19;

// void Solution() {


// }

int main(void)
{

	int e,s,m;

	cin >> e >> s >> m;	


	int year = 1;
	while(1) {
		if ((year-e) % E == 0 && (year-s) % S == 0 && (year-m) % M == 0) {
			cout << year;
			return 0;
		}
		
		year++;
	}

	return 0;
}