//
// Created by xmmmmmovo on 2020/8/28.
//
#include "main/actions.h"
#include "values/constant.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_MAX_LEN 128

int main() {
    char cmd[CMD_MAX_LEN];
    while (true) {
        int i = 0;
        updateHostname();
        printf("%s > ", hostname);
        scanf("%s", cmd);
        for (; i < commandNumber; ++i) {
            if (!strcmp(cmd, actions[i].cmd)) {
                printf("%s - %s\n", actions[i].cmd, actions[i].description);
                if (actions[i].handler != NULL) {
                    actions[i].handler();
                }
                break;
            }
        }
        if (i == commandNumber) {
            unknownAction();
        }
    }

    return 0;
}
