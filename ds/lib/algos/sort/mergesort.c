#include "stdio.h"

void merge_sort(int *, int *);

void swap(int *, int *);

void merge(int *start, int *mid, int *end, int len);


    int arr[] = {6, 12,4, 22, 67, 45, 4, 1, 8,0};

    int main() {
        printf("In Merge sort");

        int len = (sizeof(arr) / sizeof(arr[0]) - 1);
        merge_sort(arr, arr + len);
        return 0;
    }

    void merge_sort(int *start, int *end) {
        printf("In merge sort");
        int len = end - start + 1;
        int *mid = (start + (len / 2));
//base case
        if (len == 1)
            return;
        else if (len == 2) {
            int lval = *start;
            int rval = *(start + 1);
            if (lval > rval) {
                swap(start, end);
            }
            return;
        }
//divide left
        merge_sort(start, mid - 1);
//divide right
        merge_sort(mid, end);
//merge
        merge(start, mid, end, len);

    }

    void swap(int *start, int *end) {
        int buff = *start;
        *start = *end;
        *end = buff;
    }

    void merge(int *start, int *mid, int *end, int len) {
        int *lstart = start, *lend = mid - 1, *rstart = mid, *rend = end;
        int buffer[len], count = 0;
        while (lstart <= lend && rstart <= rend) {
            int left = *lstart, right = *rstart;
            if (right < left) {
                buffer[count] = right;
                rstart++;
            } else {
                buffer[count] = left;
                lstart++;
            }
            count++;
        }
        printf("hh");
        while (lstart <= lend) {
            int left = *lstart, right = *rstart;
            buffer[count] = left;
            lstart++;
            count++;
        }
        while (rstart <= rend) {
            int left = *lstart, right = *rstart;
            buffer[count] = right;
            rstart++;
            count++;
        }
        int *buff = buffer;
        while (start <= end) {
            *start = *buff;
            buff++;
            start++;
        }
    }
