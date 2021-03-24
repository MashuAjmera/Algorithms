#include <iostream>
#include <cmath>
using namespace std;

int binarySearch(int arr[], int l, int h, int k)
{
    if (l > h)
        return -1;
    int mid = floor((l + h) / 2);
    if (arr[mid] == k)
        return mid;
    else if (arr[mid] > k)
        binarySearch(arr, l, mid - 1, k);
    else if (arr[mid] < k)
        binarySearch(arr, mid + 1, h, k);
}

int main()
{
    int arr[] = {3, 6, 8, 12, 14, 17, 25, 29, 36, 42, 47, 53, 55, 62};
    int n = sizeof(arr) / sizeof(arr[0]);
    // int k = 12;
    int k = 25;
    cout << "The key is found at position: " << binarySearch(arr, 0, n - 1, k);
}