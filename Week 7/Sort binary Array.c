#include <stdio.h>
#include <stdlib.h>

int a[];

void swap(int i,int j)
{
    int temp;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;

}

void BinaryArraySorting(int a[], int n)
{
    int i,j = -1;
    for (i=0; i < n; i++)
    {

        if (a[i] < 1)
        {
            j++;
            swap(i,j);
        }
    }
}

int main()
{
   extern int a[];
   int n;
   printf("Enter Size of Array");
   scanf("%d",&n);
   printf("Enter only Binary digits in Array");
       for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    BinaryArraySorting(a, n);
    for (int i = 0; i < n; i++)
        printf("%d",a[i]);
    return 0;
}
