//
// Created by Aravind B on 15/03/23.
//
#include "stdio.h"
#include "../../../lib/algos/sort/selectionsort.c"
int main(){
    int in[]={12,11,10,9,8,7,6,5,4,3,2,1};
    int len = sizeof (in)/sizeof (in[0]);
    selectionsort(in,len);
    printf("Selection sort");
    return 0;
}