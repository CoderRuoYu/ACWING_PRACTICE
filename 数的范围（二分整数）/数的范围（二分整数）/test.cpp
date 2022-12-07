#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
const int N = 1e5 + 1;
int arr[N];
void mid_search(int arr[], int l, int r, int x)
{
    int mid;
    int i = l, j = r;
    while (l < r)
    {
        mid = l + r >> 1;
        if (arr[mid] >= x)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (x != arr[r])
    {
        printf("-1 -1\n");
        return;
    }
    else
    {
        printf("%d ", l);
        l = i, r = j;
        while (l < r)
        {
            mid = l + r + 1 >> 1;
            if (arr[mid] <= x)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        printf("%d\n", l);
    }
}
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < q; i++)
    {
        int x = 0;
        scanf("%d", &x);
        mid_search(arr, 0, n - 1, x);
    }
    return 0;
}