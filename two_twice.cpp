#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a[] = {5, 4, 1, 4, 5, 3, 1, 2, 7, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 0, shift;

    for (int i = 0; i < n; i++)
    {
        x ^= a[i];
    }

    for (int i = 0; i < 100; i++)
    {
        if (x & (1 << i))
        {
            shift = i;
            break;
        }
    }

    int y = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] & (1 << shift))
            y ^= a[i];
    }
    cout << "The two non-repeating element in the array where every other element repeats twice are: " << y << " " << (x ^ y);
}