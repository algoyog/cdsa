//
// Created by Aravind B on 17/03/23.
//
#include "stdio.h"
#include "../../lib/adt/stack.c"
int main() {
    Stack container = initialize(Array);
    for(int i=0;i<324;i++){
        push(&container,i);
    }
    printstack(&container);
}