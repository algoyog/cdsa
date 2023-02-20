#include <stdio.h>
#include "lib/linkedlist/linkedlist.h"

void testll();

void removeDup();
void recuRemoveDup();

int main() {
    printf("Hello, World!\n");
    removeDup();
    return 0;
}

void removeDup() {
    int input[] = {1, 3, 3, 3, 4, 6, 6, 7, 8};
    Node *head = ll_from_array(input, ARRAY_SIZE(input));
    //recuRemoveDup(head,head);
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


