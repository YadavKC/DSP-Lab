#include<stdio.h>
void Q_S(int arr[30],int first,int last){
   int i, j, pivot, temp,mid,median;
   mid= (first+last)/2;  //  finding median of first, mid, last element of array
   if(arr[first]<arr[mid])
   {
       if(arr[mid]<arr[last])
        median= mid;
       else
        median=last;
   }
   else if(arr[last]<arr[first])
   median=last;
   else
    median=first;

   if(first<last){
      pivot=median;   // here we take first element as pivot
      i=first;
      j=last;

      while(i<j){
         while(arr[i]<=arr[pivot]&&i<last)
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }

      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      Q_S(arr,first,j-1);
      Q_S(arr,j+1,last);

   }
}

int main(){
   int i,t, count, arr[25];

   printf("Plese Enter Size of Array ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
    scanf("%d",&arr[i]);
   t=count-1;
   Q_S(arr,t/4,3*t/4);

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",arr[i]);

   return 0;
}
