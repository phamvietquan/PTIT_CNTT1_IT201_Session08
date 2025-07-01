#include <stdio.h>
#include <stdlib.h>


int selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
        printf("%d: ",arr[i]);
    }
    printf("\n");
    selectionSort(arr,n);
    printf("cac phan tu sau khi sap xep\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ",arr[i]);
    }
    free(arr);
    return 0;
}
