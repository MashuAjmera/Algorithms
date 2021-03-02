#include <iostream>
using namespace std;

int main()
{
    int a=309; //100110101
    int i=3;

    int find=1<<i; //00001000
    (a&find)?cout<<i<<"th bit was 1. ":cout<<i<<"th bit was 0.\n";

    int set=1<<i;//00001000
    cout<<"After set, the number became "<<(a|set)<<".\n";

    int clear=~(1<<i);//11110111
    cout<<"After clear, the number is "<<(a&clear)<<".";
}