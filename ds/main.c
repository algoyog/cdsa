#include <stdio.h>
#include "lib/linkedlist/linkedlist.h"

void testll();

void removeDup();
Node* findUniqNext(Node* inp);
static int dupCount = 0;
int main() {
    printf("Hello, World!\n");
    removeDup();
    return 0;
}

void removeDup() {
    int input[] = {1, 3, 3, 3, 4, 6, 6, 7, 8};
    //int input[] = {2,4, 5, 16, 23, 34, 45, 51};
    Node *head = ll_from_array(input, ARRAY_SIZE(input));
    Node *temp = head;
    do {
        temp->next = findUniqNext(temp);
        temp=temp->next;
    } while (temp!=NULL);
    printf("Hello");
}

Node* findUniqNext(Node* inp){
    Node* next = inp->next;
    if(next == NULL) return NULL;
    Node* nextnext = next->next;
    if(nextnext==NULL) return next;
    int flag = -1;
    while(next->data == nextnext->data){
        flag = 1;
        nextnext = nextnext->next;

    }
    if(flag == 1) {
        dupCount++;
        return nextnext;
    }
    else
        return next;
}


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


