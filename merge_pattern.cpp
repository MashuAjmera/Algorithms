#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> sizes;
    sizes.push(20);
    sizes.push(30);
    sizes.push(10);
    sizes.push(5);
    sizes.push(30);
    int n = sizes.size();
    int res = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int x = sizes.top();
        sizes.pop();
        int y = sizes.top();
        sizes.pop();
        int temp = x + y;
        sizes.push(temp);
        res += temp;
    }
    cout << "The total cost of merge is: " << res;
}