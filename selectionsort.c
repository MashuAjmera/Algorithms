#include <stdio.h>
// Selection Sort

void main()
{
    int a[10], i, j, m, x;
    printf("Enter the array: ");
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<10;i++)
    {
        x=i;
        for(j=i+1;j<10;j++)
        {
            if(a[j]<a[x])
            x=j;
        }
        if(a[x]!=a[i])
        {
            m=a[x];
            a[x]=a[i];
            a[i]=m;
        }
    }
    printf("The sorted array is: ");
    for(i=0;i<10;i++)
    {
        printf("%d ", a[i]);
    }
}