#include <stdio.h>
#include "../../lib/linkedlist/linkedlist.h"

void removeDup(int* input, int size);
static int dupCount = 0;

int main() {
    //Success conditions
    int input[] = {1, 3, 3, 3, 4, 6, 6, 7, 8};
    removeDup(input,ARRAY_SIZE(input));

    int input2[] = {2,4, 5, 16, 23, 34, 45, 51};
    removeDup(input2,ARRAY_SIZE(input2));

    int input3[] = {1, 1, 3, 3, 4, 6, 6, 7, 8, 9, 10, 11};
    removeDup(input3,ARRAY_SIZE(input3));

    int input4[] = {1, 3, 3, 3, 4, 6, 6, 7, 8,9,10,11,11};
    removeDup(input4,ARRAY_SIZE(input4));

    int input5[] = {1};
    removeDup(input5,ARRAY_SIZE(input5));

    int input6[] = {1,1,1};
    removeDup(input6,ARRAY_SIZE(input6));

    int input7[] = {1,1,2};
    removeDup(input7,ARRAY_SIZE(input7));

    return 0;
}

/* Method to remove duplicate and print the count and the updated linked list*/
void removeDup(int* input, int size) {
    Node *head = ll_from_array(input, size);
    printf("\nInput count:%d ",size);
    printf("\nInput : ");ll_print(head);
    int count = 0;
    if(head==NULL){
        printf("No Input");
        return;
    }else{

        if(head->next == NULL){
            printf("\nOutput : ");ll_print(head);
            printf("\nNumber of corrupted files %d",count);
            printf("\n----------------------------------------");
            return;
        }
    }

    Node *basePtr = NULL;
    Node *cmpZone = head;
    Node *nxtPtr = head->next;
    while (cmpZone != NULL && nxtPtr != NULL) {
        int cmpDirtyFlg = 0;
        while (nxtPtr!=NULL && cmpZone->data == nxtPtr->data) {
            cmpDirtyFlg = 1;
            nxtPtr = nxtPtr->next;
        }
        if(basePtr == NULL){
            if(cmpDirtyFlg == 1) head = nxtPtr;
            else basePtr = cmpZone;
        }else{
            if(cmpDirtyFlg == 1) basePtr->next = nxtPtr;
            basePtr = cmpZone;
        }
        cmpZone = nxtPtr;
        nxtPtr = (nxtPtr!=NULL)?nxtPtr->next:NULL;
        if (cmpDirtyFlg == 1) count++;
    }
    //Printing Output
    printf("\nOutput : ");ll_print(head);
    printf("\nNumber of corrupted files %d",count);
    printf("\n----------------------------------------");
}



