#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
        printf("arr[%d]: ",arr[i]);
    }
    printf("\n");
    bubbleSort(arr,n);
    printf("cac phan tu sau khi sap xep\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: %d\n",i,arr[i]);
    }
    free(arr);
    return 0;
}
