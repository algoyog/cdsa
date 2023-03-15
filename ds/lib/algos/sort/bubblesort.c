//
// Created by Aravind B on 14/03/23.
//
#include "stdio.h"
void bubblesort(int*, int);

void bubblesort(int* inp, int sz){
    int len = sz;
    while (len>=0){
        int count=0;
        while (count<len){
            int* ptr = inp+count;
            if(*ptr > *(ptr+1)){
                int buff = *ptr;
                *ptr = *(ptr+1);
                *(ptr+1) = buff;

            }
            count++;
        }
        len--;
    }
}