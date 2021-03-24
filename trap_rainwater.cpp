#include <iostream>
using namespace std;
int main()
{
    int height[] = {3, 1, 2, 4, 0, 1, 3, 2};
    int n = sizeof(height) / sizeof(height[0]);
    int left[n], right[n], res = 0;
    left[0] = height[0], right[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++)
    {
        left[i] = max(height[i], left[i - 1]);
        right[n - i - 1] = max(height[n - i - 1], right[n - i]);
    }

    for (int i = 0; i < n; i++)
    {
        res += min(left[i], right[i]) - height[i];
    }
    cout << res << " is the total trapped rain water. ";
}