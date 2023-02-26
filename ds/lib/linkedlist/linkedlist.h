#include <stdlib.h>

#ifndef DS_LINKEDLIST_H
#define DS_LINKEDLIST_H

#endif //DS_LINKEDLIST_H
#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

typedef struct nodeType {
    int data;
    struct nodeType *next;
} Node;

/*
 * Insert next O(1)
 */
Node *ll_insert_next(Node *inputNode, int data) {
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->data = data;
    tmp->next = NULL;
    if (NULL != inputNode) {
        inputNode->next = tmp;
    }
    return tmp;
}

/*
 * Insert at last in the list O(n)
 */
Node *ll_insert(Node *head, int data) {
    Node *itr = head;
    while (itr!=NULL && itr->next != NULL) {
        itr = itr->next;
    }
    return ll_insert_next(itr, data);

}

/*
 * Search for LL node for a given position. Head position is considered 1st location.
 */
Node *ll_search_pos(Node *head, int pos) {
    Node *tmp = head;
    int count = 1;
    if (pos > 1) {
        while (pos != count && tmp->next != NULL) {
            tmp = tmp->next;
            count++;
        }
    } else {
        tmp = NULL;
    }
    if (pos > count) {
        tmp = NULL;
    }
    return tmp;
}

/*
 * Insert the node at a give position.
 * O(n)
 */
int ll_insert_rand(Node *head, int data, int pos) {
    int status = 0;
    Node *prev = ll_search_pos(head, pos - 1);
    Node *prevnextbuf = prev->next;

    Node *newnode = (Node *) malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = prevnextbuf;

    prev->next = newnode;
    return status;
}

Node* ll_from_array(int *arr, int size){
    Node* head = NULL;
    for(int i=0;i<=size-1;i++){
        if(i==0){
            head = ll_insert(NULL,*arr);//ll_init(1);
        }else{
            ll_insert(head,*arr);
        }

        arr++;
    }
    return head;
}

void ll_print(Node* head){
    Node* tmp = head;
    while(tmp!=NULL){
        printf(" %d ",tmp->data);
        tmp = tmp->next;
    }
}

//void ll_deleteNode(Node* head, Node)