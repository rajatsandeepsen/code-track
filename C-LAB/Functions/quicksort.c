#include <stdio.h>

int partition (int arr[], int LB , int UB){
       int pivot = LB;
       int start = LB;
       int end = UB;
       
       while (start < end){
              while (arr[start] <= arr[pivot] && start < UB)
                     start++ ;     
                     
              while (arr[end] > arr[pivot])
                     end-- ;
                     
              if (start < end){
                  int temp = arr[start];
                  arr[start] = arr[end];
                  arr[end] = temp;
              }
       }
       int temp = arr[pivot];
       arr[pivot] = arr[end];
       arr[end] = temp;
       
       return end;
}

void Qsort (int arr[],int LB,int UB){
       if (LB < UB){
              int LOC = partition(arr, LB, UB);
              Qsort (arr, LB, LOC-1);
              Qsort (arr, LOC+1, UB);
       }
       
}

int main (){
       int i,n;
       printf("Enter the limit of array: ");
       scanf("%d",&n);
       int arr[n];
       printf("Enter the elements for array: \n");
       for (i = 0; i < n; i++)
              scanf("%d",&arr[i]);
              
       printf("\n");
       Qsort (arr, 0, n);
       for (i = 1; i <= n; i++)
              printf("\t%d",arr[i]);
              
       printf("\n");
}

