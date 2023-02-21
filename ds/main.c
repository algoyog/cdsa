#include <stdio.h>
#include "lib/linkedlist/linkedlist.h"

void removeDup(int* input, int size);
static int dupCount = 0;

int main() {
    //Success conditions
    int input[] = {1, 3, 3, 3, 4, 6, 6, 7, 8};
    //int input[] = {2,4, 5, 16, 23, 34, 45, 51};
    //int input[] = {1, 1, 3, 3, 4, 6, 6, 7, 8, 9, 10, 11};
    //int input[] = {1, 3, 3, 3, 4, 6, 6, 7, 8,9,10,11,11};
    removeDup(input,ARRAY_SIZE(input));
    return 0;
}

void removeDup(int* input, int size) {
    Node *head = ll_from_array(input, size);
    printf("\nInput : ");ll_print(head);
    int count = 0;
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
}



