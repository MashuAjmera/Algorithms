#include <stdio.h>
// Insertion Sort

void main()
{
    int a[10], i, j, m;
    printf("Enter the array: ");
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    for(i=1;i<10;i++)
        for(j=i;j>=0;j--)
            if(a[j]<a[j-1])
            {
                m=a[j];
                a[j]=a[j-1];
                a[j-1]=m;
            }
    printf("The sorted array is: ");
    for(i=0;i<10;i++)
        printf("%d ", a[i]);
}