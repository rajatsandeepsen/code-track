// write heap sort on arrays of integers

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void heapify(int *a, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heapSort(int *a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

void printArray(int *a, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[MAX];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        a[i] = rand() % 100;

    printf("Unsorted array: ");
    printArray(a, n);

    heapSort(a, n);

    printf("Sorted array: ");
    printArray(a, n);
}
