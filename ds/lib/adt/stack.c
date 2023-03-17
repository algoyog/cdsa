//
// Created by Aravind B on 17/03/23.
//
#include "../linkedlist/linkedlist.h"

enum impl_backend{Array, LinkedList};
const int  LIMIT = 100;
const float PERCENT_EXPAND = .8;

typedef struct Stack{
    enum  impl_backend type;
    int len;
    int capacity;
    int* input;
    Node* head;
} Stack;

Stack initialize(enum impl_backend);
void push(Stack*, int);
void printstack(Stack*);

Stack initialize(enum impl_backend input){
    Stack stk;
    stk.type=input;
    stk.len=0;
    stk.input=(int*) calloc(LIMIT, sizeof(int));
    stk.capacity=LIMIT;
    return stk;
}

void push(Stack* ref, int element){
    int curr_limit=PERCENT_EXPAND * ref->capacity;
    if(ref->len>curr_limit){
        ref->capacity = ref->capacity+LIMIT;
        ref->input = realloc(ref->input,ref->capacity);
    }
    ref->len++;
    *(ref->input+ref->len) = element;
}

void printstack(Stack* ref){
    int size = ref->len;
    while (size>0){
        printf("%d ",*(ref->input  +size));
        size--;
    }
}