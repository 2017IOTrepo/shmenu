//
// Created by xmmmmmovo on 2020/8/29.
//

#include "linkedlist.h"
#include <stddef.h>
#include <stdlib.h>

struct _LinkedList {
    tLinkedListNode *head;
    tLinkedListNode *tail;
    int size;
};

tLinkedList *createLinkedList() {
    tLinkedList *pLinkedList = (tLinkedList *) malloc(sizeof(tLinkedList));
    if (pLinkedList == NULL) {
        return NULL;
    }
    pLinkedList->head = NULL;
    pLinkedList->tail = NULL;
    pLinkedList->size = 0;
    return pLinkedList;
}

int deleteLinkedList(tLinkedList *pLinkedList) {
    if (pLinkedList != NULL) {
        return FAILURE;
    }
    while (pLinkedList->head != NULL) {
    }

    return SUCCESS;
}
