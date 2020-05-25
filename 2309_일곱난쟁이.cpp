#include <iostream>
#include <algorithm>


using namespace std;

int solution(int sum, int *arr)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - (arr[i] + arr[j]) == 100) // 선택한 난쟁이 2명의 키를 뺐을 때 100일시 -1 저장후 종료 
			{
				arr[i] = -1;
				arr[j] = -1;
				return 0;
			}
		}
	}
}
int main()
{
	int arr[9];
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	solution(sum, arr);

	sort(arr,arr+9);

	for (int i = 2; i < 9; i++) // -1로 저장된 값은 배열 맨앞 2자리를 차치하기 때문에 인덱스 2번부터 출력 
	{
		cout << arr[i] << endl;
	}
}