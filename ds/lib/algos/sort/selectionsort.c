//
// Created by Aravind B on 15/03/23.
//

#include "stdio.h"

void selectionsort(int*,int);


void selectionsort(int* in,int len){
    printf("Selection sort");
    int* slowptr = in;
    int* fastptr = in+1;
    int* endptr = (in+len-1);
    int slowcount =0,fastcount=0;
    while (slowcount<len){
        int buff = *slowptr;
        int flag = -99;
        fastcount = slowcount+1;
        fastptr = in+fastcount;
        while (fastcount<len){
            if((*fastptr)<(*slowptr)){
                buff=*fastptr;
                flag =fastcount;
            }
            fastcount++;
            fastptr++;
        }
        if(flag!=-99){
            int swapval = *(in+slowcount);
            *(in+slowcount) = buff;
            *(in+flag) = swapval;
        }
        slowcount++;
        slowptr++;
    }

    printf("Selection sort");
}