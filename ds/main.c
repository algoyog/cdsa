#include <stdio.h>
#include "lib/linkedlist/linkedlist.h"
void testll();

int main() {
    printf("Hello, World!\n");
    testll();
    return 0;
}

void testll(){
    Node head = ll_init(1);
    ll_insert_next(&head,2);
    ll_insert_last(&head,3);
    printf("%d",head.data);
    printf("%d",head.next->data);
    printf("%d",head.next->next->data);
}


