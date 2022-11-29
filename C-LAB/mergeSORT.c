#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r){
printf("\n33");
int i = 0, j = 0, k = l;
    int n1 = m - l + 1;
    int n2 = r - m;


       int LEFT[n1];
       int RIGHT[n2];
       
       for (i=0; i<n1; i++){
              LEFT[i] = arr[l + 1];
              printf("\n44");
       }
       for (j=0; j<n2; j++){
              RIGHT[j] = arr[m + 1 + j];
              printf("\n55");
       }
       
       while(i < n1 && j < n2){
              if(LEFT[i] <= RIGHT[j]){
                     arr[k] = LEFT[i];
                     i++;
                     printf("\n66");
              }
              else {
                     arr[k] = RIGHT[j];
                     j++;
                     printf("\n77");
              }
              k++;
       }
       while(i < n1){
              arr[k] = LEFT[i];
              i++;
              k++;
              printf("\n88");
       }
       while(j < n2){
              arr[k] = RIGHT[j];
              j++;
              k++;
              printf("\n99");
       }
}

void mergeSORT(int arr[], int l, int r){
       if (l < r){
       printf("\n11");
              int m = l + (r - l) / 2;
              mergeSORT(arr, l, m);
              mergeSORT(arr, m + 1, r);
              merge(arr,l ,m ,r);
       }
       printf("\n22");
}


void display (int arr[], int n){
       int i;
       for (i = 0; i < n; i++ ){
            printf("\t%d",arr[i]);
       }
       printf("\n");
}

int main(){
              int n;
              printf("Enter array limit : ");
              scanf("%d",&n);
              int arr[n];
              int i;
              printf("Enter elements for array : \n");
              for (i = 0; i < n; i++ ){
                     scanf("%d",&arr[i]);
              }
              printf("\nBefore Sorting : ");
              display(arr, n);
              mergeSORT(arr,0,n-1);
              printf("After Sorting : ");
              display(arr, n);
     
}
