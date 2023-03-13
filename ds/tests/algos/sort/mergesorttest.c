#include "stdio.h"
#include "../../../lib/algos/sort/mergesort.c"
int main() {
    printf("In Merge sort");
    int arr[] = {6, 12,4, 22, 67, 45, 4, 1, 8,0};
    int len = (sizeof(arr) / sizeof(arr[0]) - 1);
    merge_sort(arr, arr + len);
    return 0;
}
