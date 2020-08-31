//
// Created by xmmmmmovo on 2020/8/28.
//
#include "main/actions.h"
#include "main/menu.h"

int main() {
    setPrompt("zhazha menu > ");
    addMenuItem("quit", "quit the program", quitAction);
    addMenuItem("date", "tell you the when", dateAction);
    addMenuItem("rand", "rand the number", randomAction);
    addMenuItem("pwd", "show your now directory", pwdAction);
    addMenuItem("hello", "say hello to you", helloAction);
    addMenuItem("sys", "tell you system messages", sysAction);
    addMenuItem("version", "menu v5.0", versionAction);
    setUnknownCommandCallback(unknownAction);
    executeMenu();
    return 0;
}
