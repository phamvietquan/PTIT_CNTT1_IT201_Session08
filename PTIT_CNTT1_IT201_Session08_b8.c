#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int n) {
    for (int i =0; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int linearSearch(int arr[], int n, int search) {
    int found = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            found = i;
            return found;
        }
    }
    if (found == -1) {
        printf("khong ton tai phan tu");
    }
}

int binarySearch(int arr[], int n, int search) {
    int left=0, right=n-1;
    while (left <= right) {
        int mid = (left+right)/2;
        if (arr[mid]==search) return mid;
        if (arr[mid]<search) {
            left = mid+1;
        }else if (arr[mid]>search) {
            right = mid-1;
        }
    }
    return -1;
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
    printf("mang truoc khi sap xep:");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
        if(i!=n-1) printf(",");
    }
    printf("\n");
    insertionSort(arr, n);
    printf("mang sau khi sap xep:");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
        if(i!=n-1) printf(",");
    }
    printf("\n");
    int search;
    printf("Nhan phan tu can tim kiem:");
    scanf("%d", &search);
    int tuyenTinh = linearSearch(arr, n, search);
    printf("phan tu can tim o vi tri(Tuyen Tinh): %d\n",tuyenTinh);

    int nhiPhan=binarySearch(arr, n, search);
    printf("phan tu can tim o vi tri(Nhi Phan): %d\n", nhiPhan);
    free(arr);
    return 0;
}
