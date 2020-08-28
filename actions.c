//
// Created by xmmmmmovo on 2020/8/28.
//

#include "actions.h"
#include "constant.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void helpAction() {
    printf("command help:\n");
    for (int i = 0; i < commandNumber; ++i) {
        printf("%s: %s\n", actions[i].name, actions[i].description);
    }
}

void quitAction() {
    exit(0);
}

void dateAction() {
    time_t now = time(NULL);
    // ps 没法用std::move好烦啊
    printf("now time is : %s\n", ctime(&now));
}

void randomAction() {
    int seed = 0;
    int maxValue = 1;
    printf("please enter a seed value\n");
    scanf("%d", &seed);
    srand(seed);
    printf("please enter the max value\n");
    scanf("%d", &maxValue);
    printf("rand answer is: %d\n", rand() % maxValue);
}

void pwdAction() {
    char *buffer;
    if ((buffer = getcwd(NULL, 0)) == NULL) {
        perror("getcwd error");
    } else {
        printf("%s\n", buffer);
        free(buffer);
    }
}

void helloAction() {
    char hostname[128];
    gethostname(hostname, sizeof(hostname));
    printf("hello, %s\n", hostname);
}

void sysAction() {
    FILE *osFile = fopen("/proc/version", "r");
    if (osFile == NULL) {
        printf("failed to open version file\n");
    }
    char szTest[1000] = {0};
    while (!feof(osFile)) {
        memset(szTest, 0, sizeof(szTest));
        fgets(szTest, sizeof(szTest) - 1, osFile);// leave out \n
        printf("%s", szTest);
    }
    fclose(osFile);
}

void unknownAction() {
    printf("Unknown command\n");
}
