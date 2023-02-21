#include <stdio.h>
#include "lib/linkedlist/linkedlist.h"

void testll();

void removeDup();

Node *findUniqNext(Node *inp);

static int dupCount = 0;

int main() {
    printf("Hello, World!\n");
    removeDup();
    return 0;
}

void removeDup() {
    //Success conditions
    //int input[] = {1, 3, 3, 3, 4, 6, 6, 7, 8};
    //int input[] = {2,4, 5, 16, 23, 34, 45, 51};
    //Failed conditions. TODO
    //int input[] = {1, 1, 3, 3, 4, 6, 6, 7, 8, 9, 10, 11};
    int input[] = {1, 3, 3, 3, 4, 6, 6, 7, 8,9,10,11,11};
    Node *head = ll_from_array(input, ARRAY_SIZE(input));
    printf("Hello");
    Node *basePtr = NULL;
    Node *cmpZone = head;
    Node *nxtPtr = head->next;
    while (cmpZone != NULL && nxtPtr != NULL) {
        int cmpDirtyFlg = 0;
        while (cmpZone->data == nxtPtr->data) {
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
        nxtPtr = nxtPtr->next;
    }
    printf("Hello");
}


/*Node *findUniqNext(Node *inp) {
    Node *next = inp->next;
    if (next == NULL) return NULL;
    Node *nextnext = next->next;
    if (nextnext == NULL) return next;
    int flag = -1;
    while (next->data == nextnext->data) {
        flag = 1;
        nextnext = nextnext->next;
    }
    if (flag == 1) {
        dupCount++;
        return nextnext;
    } else
        return next;
}
*/

void testll() {
    Node head = *ll_insert(NULL, 1);//ll_init(1);
    ll_insert(&head, 2);
    ll_insert(&head, 3);
    ll_insert(&head, 4);
    ll_insert_rand(&head, 0, 3);
    printf("%d", head.data);
    printf("%d", head.next->data);
    printf("%d", head.next->next->data);
}


