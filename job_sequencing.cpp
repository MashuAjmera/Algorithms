#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int profits[] = {35, 30, 25, 20, 15, 12, 5};
    int deadlines[] = {3, 4, 4, 2, 3, 1, 2};
    int jobs = sizeof(deadlines) / sizeof(deadlines[0]);
    int slots = *max_element(deadlines, deadlines + jobs), count = 0;
    int sequence[slots] = {};

    for (int i = 0; i < jobs && count <= 4; i++)
        for (int j = deadlines[i] - 1; j >= 0; j--)
            if (sequence[j] == 0)
            {
                sequence[j] = i + 1;
                count++;
                break;
            }

    cout << "The sequence of selected job is:";
    for (int i = 0; i < slots; i++)
        cout << " " << sequence[i];
}