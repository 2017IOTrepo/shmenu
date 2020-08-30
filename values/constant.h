//
// Created by xmmmmmovo on 2020/8/28.
//

#ifndef SHMENU_CONSTANT_H
#define SHMENU_CONSTANT_H

#define NAME_NUMBER 32
#define DESCRIPTION_NUMBER 128
#define HOST_NAME_LENGTH 128

typedef struct _ActionMsg {
    char cmd[NAME_NUMBER];
    char description[DESCRIPTION_NUMBER];
    int (*handler)();

} ActionMsg;

extern ActionMsg actions[];

extern int commandNumber;

extern char hostname[];// 主机名

void updateHostname();

ActionMsg *findAction(char *cmd);

#endif//SHMENU_CONSTANT_H
