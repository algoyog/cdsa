//
// Created by Aravind B on 14/03/23.
//
#include "stdio.h"
#include "../../../lib/algos/sort/bubblesort.c"
int main(){
    printf("In bubble sort");
    int arr[] = {6, 12,4, 22, 67, 45, 4, 1, 8};
    int len = (sizeof(arr) / sizeof(arr[0]) - 1);
    bubblesort(arr,len);
    return 0;

}
