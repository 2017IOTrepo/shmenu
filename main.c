//
// Created by xmmmmmovo on 2020/8/28.
//
#include "actions.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char cmd[128];
    while (true) {
        scanf("%s", cmd);
        if (!strcmp(cmd, "help")) {
            helpAction();
        } else if (!strcmp(cmd, "quit")) {
            quitAction();
        } else if (!strcmp(cmd, "date")) {
            dateAction();
        } else if (!strcmp(cmd, "rand")) {
            randomAction();
        } else if (!strcmp(cmd, "pwd")) {
            pwdAction();
        } else if (!strcmp(cmd, "hello")) {
            helloAction();
        } else if (!strcmp(cmd, "sys")) {
            sysAction();
        } else {
            unknownAction();
        }
    }

    return 0;
}
