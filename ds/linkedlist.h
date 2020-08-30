//
// Created by xmmmmmovo on 2020/8/29.
//

#ifndef SHMENU_LINKEDLIST_H
#define SHMENU_LINKEDLIST_H

#define SUCCESS 1
#define FAILURE 0

typedef struct _LinkedListNode {
    struct _LinkedListNode *next;
} tLinkedListNode;

typedef struct _LinkedList tLinkedList;

tLinkedList *createLinkedList();

int deleteLinkedList(tLinkedList *pLinkedList);

int addLinkedListNode(tLinkedList *pLinkedList, tLinkedListNode *pNode);

int deleteLinkedListNode(tLinkedList *pLinkedList, tLinkedListNode *pNode);

tLinkedListNode *findLinkedListNode(tLinkedList *pLinkedList, int condition(tLinkedListNode *pNode));

tLinkedListNode *getLinkedListHead(tLinkedList *pLinkedList);

tLinkedListNode *getNextLinkedListNode(tLinkedList *pLinkedList, tLinkedListNode *pNode);

#endif//SHMENU_LINKEDLIST_H
