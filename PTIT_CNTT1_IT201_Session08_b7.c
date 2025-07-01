#include <stdio.h>
#include <stdlib.h>


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for (int j = low; j<=high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

int quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}
int main() {
    int n;
    do {
        printf("Nhan n: ");
        scanf("%d", &n);
        if (n<0 || n>1000) {
            printf("n phai nho hon 1000 va lon hon 0\n");
        }
    } while (n<0 || n>1000);
    int *arr=(int *)malloc(n*sizeof(int));
    if (arr==NULL) {
        printf("khong the cap phat bo nho\n");
        return 1;
    }
    printf("Nhan phan tu cua mang\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ",i);
        scanf("%d", &arr[i]);
    }
    printf("cac phan tu truoc khi sap xep\n");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    quickSort(arr, 0, n-1);
    printf("cac phan tu sau khi sap xep\n");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}
