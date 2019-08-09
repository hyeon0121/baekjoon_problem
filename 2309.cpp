#include<iostream>  
#include<stack>
#include<string>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 9;
int arr[N];

void Solution(int n) {

	for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {

			if (n - (arr[i] + arr[j]) == 100) {

				for (int k = 0; k < N; k++) {
					if (k!=i && k!=j) {
						cout << arr[k] << endl;
					}
				}

				return;
			}
			
		}
	}

}

int main(void)
{

	for (int i = 0; i < N; i++) {
		cin >> arr[i];	
	}

	sort(arr, arr+N);

	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum += arr[i];	
	}

	Solution(sum);
	

	return 0;
}