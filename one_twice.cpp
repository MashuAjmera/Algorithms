#include <iostream>
using namespace std;

int main()
{
    int a[] = {5, 4, 1, 4, 5, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x ^= a[i];
    }
    cout << "The only non-repeating element in the array where every other element repeats twice is: " << x;
}