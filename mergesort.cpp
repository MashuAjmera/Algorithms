#include <stdio.h>
// Merge Sort

void merge(int a, int low, int mid, int mid+1, int high)
{
    int i, j, k;
    for(i=low , j=mid+1 , k=low; i<mid && j<high; k++)
    {
        if(a[i]==a[j])
        {
            a[k]=a[i];
            i++;
            j++;
        }
        else if(a[i]<a[j])
        {
            a[k]=a[i];
            i++;
        }
        else
        {
            a[k]=a[j];
            j++;
        }
    }
    for(; i<mid; i++ , k++)
            a[k]=a[i];
    for(; j<high; j++ , k++)
            a[k]=a[j];
}

void mergesort(int a, int low, int high)
{
    if(low>=high)
        return;
    int mid=(low+high)/2;
    mergesort(int a, low, mid);
    mergesort(int a, mid+1, high);
    merge(int a, low, mid, mid+1, high);
}

void main()
{
    int n,i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array: ");
    for(i=0;i<10;i++)
        scanf("%d", &a[i]);
    mergesort(a, 0, n-1);
    printf("The sorted array is: ");
    for(i=0;i<10;i++)
        printf("%d", &a[i]);
}