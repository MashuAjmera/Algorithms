#include <iostream>
using namespace std;

int main()
{
    int a=22, b=27;
    int count=0;
    int mask=a^b;
    while(mask){
        mask=mask&(mask-1);
        count++;
    }
    cout<<"Number of bits to change: "<<count;
}