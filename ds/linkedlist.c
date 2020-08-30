//
// Created by xmmmmmovo on 2020/8/29.
//

#include "linkedlist.h"
#include <stddef.h>
#include <stdlib.h>

struct _LinkedList {
    tLinkedListNode *head;
    tLinkedListNode *tail;
    int              size;
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
        tLinkedListNode *tmp = pLinkedList->head;
        pLinkedList->head    = pLinkedList->head->next;
        pLinkedList->size -= 1;
        free(tmp);
    }
    pLinkedList->head = NULL;
    pLinkedList->tail = NULL;
    pLinkedList->size = 0;
    free(pLinkedList);
    return SUCCESS;
}

int addLinkedListNode(tLinkedList *pLinkedList, tLinkedListNode *pNode) {
    if (pLinkedList == NULL || pNode == NULL) {
        return FAILURE;
    }
    pNode->next = NULL;
    if (pLinkedList->head == NULL) {
        pLinkedList->head = pNode;
    }
    if (pLinkedList->tail == NULL) {
        pLinkedList->tail = pNode;
    } else {
        pLinkedList->tail->next = pNode;
        pLinkedList->tail       = pNode;
    }
    pLinkedList->size += 1;
    return SUCCESS;
}

int deleteLinkedListNode(tLinkedList *pLinkedList, tLinkedListNode *pNode) {
    if (pLinkedList == NULL || pNode == NULL) {
        return FAILURE;
    }
    if (pLinkedList->head == pNode) {
        pLinkedList->head = pLinkedList->head->next;
        pLinkedList->size -= 1;
        if (pLinkedList->size == 0) {
            pLinkedList->tail = NULL;
        }
        return SUCCESS;
    }
    tLinkedListNode *tmp = pLinkedList->head;
    while (tmp != NULL) {
        if (tmp->next == pNode) {
            tmp->next = pNode->next->next;
            pLinkedList->size -= 1;
            if (pLinkedList->size == 0) {
                pLinkedList->tail = NULL;
            }
            return SUCCESS;
        }
        tmp = tmp->next;
    }

    return FAILURE;
}
tLinkedListNode *findLinkedListNode(tLinkedList *pLinkedList, int (*condition)(tLinkedListNode *, void *args), void *args) {
    if (pLinkedList == NULL || condition == NULL) {
        return NULL;
    }
    tLinkedListNode *tmp = pLinkedList->head;
    while (tmp != pLinkedList->tail) {
        if (condition(tmp, args) == SUCCESS) {
            return tmp;
        }
    }
    return NULL;
}

tLinkedListNode *getLinkedListHead(tLinkedList *pLinkedList) {
    if (pLinkedList == NULL)
        return NULL;

    return pLinkedList->head;
}

tLinkedListNode *getNextLinkedListNode(tLinkedList *pLinkedList, tLinkedListNode *pNode) {
    if (pLinkedList == NULL || pNode == NULL) {
        return NULL;
    }
    tLinkedListNode *pTempNode = pLinkedList->head;
    while (pTempNode != NULL) {
        if (pTempNode == pNode) {
            return pTempNode->next;
        }
        pTempNode = pTempNode->next;
    }
    return NULL;
}
