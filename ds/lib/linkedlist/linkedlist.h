//
// Created by Aravind B on 20/02/23.
//

#include <stdlib.h>

#ifndef DS_LINKEDLIST_H
#define DS_LINKEDLIST_H

#endif //DS_LINKEDLIST_H

typedef struct nodeType {
    int data;
    struct nodeType *next;
}Node;

/*
 * Initialize the linked list O(1)
 */
Node ll_init(int data){
    Node *tmp = (Node *)malloc(sizeof (Node));
    tmp->data = data;
    tmp->next = NULL;
    return *tmp;

}

/*
 * Insert next O(1)
 */
void ll_insert_next(Node* inputNode, int data){
    Node *tmp = (Node *)malloc(sizeof (Node));
    tmp->data = data;
    tmp->next = NULL;
    inputNode->next=tmp;
}

/*
 * Insert last O(n)
 */
void ll_insert_last(Node* head, int data){
    Node* itr = head;
    while(itr->next!=NULL){
        itr = itr->next;
    }
    ll_insert_next(itr,data);
}

void ll_insert_rand(Node* head, int data, int pos){

}