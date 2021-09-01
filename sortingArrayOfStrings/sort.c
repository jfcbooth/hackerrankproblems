#include <stdio.h>



void swap(int* arr, const int pos1, const int pos2){
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int main(void){
    int arr[8] = {5, 3, 6, 7, 4, 7, 2, 3};

    for(int i = 0; i < 8; i++){
        for(int j = i; j > 0; j--){
            if(arr[j] < arr[j-1]){
                swap(arr, j, j-1);
            }
        }
    }

    for(int i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}