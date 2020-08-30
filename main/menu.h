//
// Created by xmmmmmovo on 2020/8/30.
//

#ifndef SHMENU_MENU_H
#define SHMENU_MENU_H

int addMenuItem(char *cmd, char *description, int (*handler)());

int setPrompt(char *str);

int executeMenu();

#endif//SHMENU_MENU_H
