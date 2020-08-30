//
// Created by xmmmmmovo on 2020/8/30.
//

#include "menu.h"
#include "../ds/linkedlist.h"
#include <string.h>
#include <unistd.h>

#define CMD_MAX_LEN 32
#define DESCRIPTION_MAX_LEN 128

char prompt[CMD_MAX_LEN] = "Cmd > ";
tLinkedList *listHead = NULL;

typedef struct _ActionMsgNode {
    char *cmd;
    char *description;
    int (*handler)();

} tActionMsgNode;

int addMenuItem(char *cmd, char *description, int (*handler)()) {
    return 0;
}

int setPrompt(char *str) {
    if (str == NULL)
        return 0;
    strcpy(prompt, str);
    return 1;
}

int executeMenu() {
    return 0;
}
