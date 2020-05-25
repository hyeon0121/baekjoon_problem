#include<iostream>

using namespace std;

int arr[12];
int n;
int opr[4];
int max_num, min_num;
void dfs(int o1, int o2, int o3, int o4, int sum, int cnt) {
	if (cnt == n) {
		if (max_num < sum) max_num = sum;
		if (min_num > sum) min_num = sum;
		return;
	}

	if (o1 > 0) dfs(o1-1, o2, o3, o4, sum+arr[cnt], cnt+1);
	if (o2 > 0) dfs(o1, o2-1, o3, o4, sum-arr[cnt], cnt+1);
	if (o3 > 0) dfs(o1, o2, o3-1, o4, sum*arr[cnt], cnt+1);
	if (o4 > 0) dfs(o1, o2, o3, o4-1, sum/arr[cnt], cnt+1);
}
int main() {
	cin >> n;
	min_num = 1000000001;
	max_num = -1000000001;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; ++i) {
		cin >> opr[i];
	}

	dfs(opr[0],opr[1],opr[2],opr[3],arr[0],1);

	cout << max_num << "\n";
	cout << min_num;

	return 0;
}