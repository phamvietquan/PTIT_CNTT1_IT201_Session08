#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[],int n) {
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

int binarySearch(int arr[],int n,int search) {
    int left=0,right=n-1;
    while (left<=right) {
        int mid=(left+right)/2;
        if (arr[mid]==search) {
            return mid;
        }
        if (arr[mid]<search) {
            left=mid+1;
        }else if (arr[mid]>search) {
            right=mid-1;
        }
    }
    return -1;
}
int main() {
    int n;
    do {
        printf("Nhap n");
        scanf("%d", &n);
        if (n<0 || n>1000) {
            printf("N phai nho hon 1000 va lon hon 0\n");
        }
    } while (n<0 || n>1000);
    int *arr=(int *) malloc(n*sizeof(int));
    if (arr==NULL) {
        printf("Khong the cap phat bo nho");
        return 1;
    }
    printf("Nhap cac phan tu cua mang\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]", i+1);
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr,n);
    printf("cac phan tu cua mang:");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i!=n-1) printf(",");
    }
    printf("\n");
    int search;
    printf("Nhap phan tu can tim kiem");
    scanf("%d", &search);
    int result= binarySearch(arr,n,search);
    if (result==-1) {
        printf("phan tu khong ton tai\n");
    }else {
        printf("phan tu o vi tri: %d", result);
    }
    free(arr);
    return 0;
}
