#include <stdio.h>
#include <stdlib.h>

void merge_sort(int i, int j, int a[], int temp[])
 {
    if (j <= i)
    {
        return;
    }
    int mid = (i + j) / 2;



    merge_sort(i, mid, a, temp);
    merge_sort(mid + 1, j, a, temp);

    int pointer_left = i;
    int pointer_right = mid + 1;
    int k;
    for (k = i; k <= j; k++)
    {
        if (pointer_left == mid + 1)
        {
            temp[k] = a[pointer_right];
            pointer_right++;
        }
        else if (pointer_right == j + 1)
        {
            temp[k] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right])
        {
            temp[k] = a[pointer_left];
            pointer_left++;
        }
        else
        {
            temp[k] = a[pointer_right];
            pointer_right++;
        }
    }

    for (k = i; k <= j; k++)
    {
        a[k] = temp[k];
    }
}


int main()
 {
  int a[100], temp[100],n,i,I,R,d, swap;

  printf("Enter the Size of Array :\n");
  scanf("%d", &n);

  printf("Enter Array Elements\n", n);

  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

    printf("Enter Value of I Starting Point to be Sorted");
    scanf("%d",&I);
    printf("Enter Value of R Starting Point to be Sorted");
    scanf("%d",&R);
    if(I>n||R>n||I>R)
    {
        printf("I And R are not in Required format");
        exit(0);
    }

  merge_sort(I, R, a, temp);

  printf("Sorted Array is :\n");

  for (i = 0; i < n; i++)
     printf("%d\t", a[i]);

  return 0;
}
