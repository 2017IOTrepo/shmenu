//
// Created by xmmmmmovo on 2020/8/28.
//

#include "constant.h"
#include "../main/actions.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int commandNumber = 7;

ActionMsg actions[16] = {
        {"help", "describe commands briefly", helpAction},
        {"quit", "quit the program", quitAction},
        {"date", "tell you the when", dateAction},
        {"rand", "rand the number", randomAction},
        {"pwd", "show your now directory", pwdAction},
        {"hello", "say hello to you", helloAction},
        {"sys", "tell you system messages", sysAction},
        {"version", "menu v1.0", versionAction}};

char hostname[HOST_NAME_LENGTH];

void updateHostname() {
    gethostname(hostname, HOST_NAME_LENGTH);
}

ActionMsg *findAction(char *cmd) {
    for (int i = 0; i < commandNumber; ++i) {
        if (!strcmp(cmd, actions[i].cmd)) {
            return &actions[i];
        }
    }

    return NULL;
}