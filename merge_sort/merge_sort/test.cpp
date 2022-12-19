#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int temp[100];
void merge_sort(int arr[], int l, int r)
{
	if (l >= r)
		return;
	int mid = l + r >> 1;
	merge_sort(arr, l, mid);
	merge_sort(arr, mid + 1, r);
	int k = 0;
	int i = l;
	int j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid)temp[k++] = arr[i++];
	while (j <= r)temp[k++] = arr[j++];
	for (int w = l,k = 0; w <= r; w++,k++)
	{
		arr[w] = temp[k];
	}
}
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0,0,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	merge_sort(arr, 0, sz - 1);
	for (int i = 0; i < sz; i++)
		cout << arr[i] << ' ';
	return 0;
}