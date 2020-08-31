//
// Created by xmmmmmovo on 2020/8/30.
//

#include "menu.h"
#include "../ds/linkedlist.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CMD_MAX_LEN 32
#define DESCRIPTION_MAX_LEN 128

int defaultUnknownCommandCallback() {
    printf("unknown command\n");
    return 1;
}

char         prompt[CMD_MAX_LEN]                     = "Cmd > ";
tLinkedList *listHead                                = NULL;
int (*unknownCommandHandler)(int argc, char *argv[]) = defaultUnknownCommandCallback;

typedef struct _ActionMsgNode {
    // 这里必须放在第一个，不然会强转失败
    tLinkedListNode *next;
    char *           cmd;
    char *           description;
    // 命令可能会有参数，所以函数需要添加argc argv
    int (*handler)(int argc, char *argv[]);
} tActionMsgNode;

int addMenuItem(char *cmd, char *description, int (*handler)()) {
    tActionMsgNode *pNode = NULL;
    if (listHead == NULL) {
        listHead = createLinkedList();
    }
    pNode              = (tActionMsgNode *) malloc(sizeof(tActionMsgNode));
    pNode->cmd         = cmd;
    pNode->description = description;
    pNode->handler     = handler;
    addLinkedListNode(listHead, (tLinkedListNode *) pNode);
    return 1;
}

int setPrompt(char *str) {
    if (str == NULL)
        return 0;
    strcpy(prompt, str);
    return 1;
}

int setUnknownCommandCallback(int (*_unknownCommandHandler)()) {
    unknownCommandHandler = _unknownCommandHandler;
    return 1;
}

void showAllCmd() {
    tActionMsgNode *pNode = (tActionMsgNode *) getLinkedListHead(listHead);
    while (pNode != NULL) {
        printf("%s - %s\n", pNode->cmd, pNode->description);
        pNode = (tActionMsgNode *) getNextLinkedListNode(listHead, (tLinkedListNode *) pNode);
    }
}

void helpAction() {
    printf("command help:\n");
    showAllCmd();
}

int condition(tLinkedListNode *pLinkedListNode, void *arg) {
    char *          cmd   = (char *) arg;
    tActionMsgNode *pNode = (tActionMsgNode *) pLinkedListNode;
    if (!strcmp(pNode->cmd, cmd)) {
        return SUCCESS;
    }
    return FAILURE;
}

int executeMenu() {
    addMenuItem("help", "describe commands briefly", helpAction);
    while (true) {
        char  cmd[CMD_MAX_LEN];
        char *pcmd = NULL;
        printf("%s", prompt);
        scanf("%s", cmd);
        //        pcmd = fgets(cmd, CMD_MAX_LEN, stdin);
        //        if (pcmd == NULL) {
        //            continue;
        //        }
        tActionMsgNode *pNode = (tActionMsgNode *) findLinkedListNode(listHead, condition, cmd);
        if (pNode == NULL) {
            unknownCommandHandler(0, NULL);
            continue;
        }

        printf("%s - %s\n", pNode->cmd, pNode->description);
        if (pNode->handler != NULL) {
            pNode->handler(0, NULL);
        }
    }

    return 0;
}
