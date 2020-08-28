//
// Created by xmmmmmovo on 2020/8/28.
//

#ifndef SHMENU_CONSTANT_H
#define SHMENU_CONSTANT_H

#define NAME_NUMBER 32
#define DESCRIPTION_NUMBER 128
#define HOST_NAME_LENGTH 128

struct _ActionMsg {
    char cmd[NAME_NUMBER];
    char description[DESCRIPTION_NUMBER];
    int (*handler)();
};

typedef struct _ActionMsg ActionMsg;

extern ActionMsg actions[];

extern int commandNumber;

extern char hostname[]; // 主机名

void updateHostname();

#endif//SHMENU_CONSTANT_H
