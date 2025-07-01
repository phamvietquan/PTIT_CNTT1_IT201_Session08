#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    do {
        printf("Please input n:");
        scanf("%d", &n);
        if (n<0 || n>1000) {
            printf("Please input a number between 0 and 1000");
        }
    } while (n<0 || n>1000);
    int *arr=(int *) malloc(n*sizeof(int));
    if (arr==NULL) {
        printf("Khong the cap phat bo nho");
        free(arr);
        return 1;
    }
    printf("Nhap cac phan tu cua mang");
    for (int i=0;i<n;i++) {
        printf("arr[%d]:", i);
        scanf("%d", &arr[i]);
    }
    int search;
    int found=-1;
    printf("Nhap phan tu can tim");
    scanf("%d", &search);
    for (int i=0;i<n;i++) {
        if (arr[i]==search) {
            printf("vi tri thu: %d",i);
            found=i;
        }
    }
    if (found==-1) {
        printf("Khong ton tai phan tu");
    }

    free(arr);
    return 0;
}
// do phuc tap thoi gian la : O(n)
