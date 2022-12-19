#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void quick_sort(int arr[], int l, int r)
{
	if (l >= r)
		return;
	int x = arr[l + r >> 1];
	int i = l - 1;
	int j = r + 1;
	while (i < j)
	{
		do i++; while (arr[i] < x);
		do j--; while (arr[j] > x);
		if (i < j)
		{
			int tem = arr[i];
			arr[i] = arr[j];
			arr[j] = tem;
		}
	}
	quick_sort(arr, l, j);
	quick_sort(arr, j + 1, r);
}
int main()
{
	int arr[] = { 5,2,8,7,9,6,1,3,4 };
	quick_sort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << ' ';
	}
	return 0;
}
