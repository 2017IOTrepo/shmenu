//
// Created by xmmmmmovo on 2020/8/28.
//

#ifndef SHMENU_CONSTANT_H
#define SHMENU_CONSTANT_H

struct _ActionMsg {
    char name[32];
    char description[128];
};

typedef struct _ActionMsg ActionMsg;

extern ActionMsg actions[];

extern int commandNumber;

#endif//SHMENU_CONSTANT_H
