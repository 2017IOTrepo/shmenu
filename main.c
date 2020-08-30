//
// Created by xmmmmmovo on 2020/8/28.
//
#include "main/actions.h"
#include "values/constant.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ds/linkedlist.h"

#define CMD_MAX_LEN 128

int main() {
    char cmd[CMD_MAX_LEN];
    while (true) {
        updateHostname();
        printf("%s > ", hostname);
        scanf("%s", cmd);

        ActionMsg *action = findAction(cmd);
        if (action == NULL) {
            unknownAction();
            continue;
        }
        printf("%s - %s\n", action->cmd, action->description);
        if (action->handler != NULL)
            action->handler();
    }

    return 0;
}
