#include <stdio.h>
#include <sys/stat.h> // for mkdir
#include <stdlib.h> // for realpath function
#include <dirent.h> // for DIR

#include "configuration/configuration.h"
#include "files/files.h"

char *getInDirectory(void){
    struct Configuration config;
    static char guardrails_path[PATH_MAX];

    config.directname = "/tmp/guardrails";

    int workingDir = listDirect(config.directname);

    if (workingDir == 1){
        config.check = mkdir(config.directname, 0777);
        if (!config.check){
            printf("created folder");
        }
    } else{
        config.check = 1;
    }

    if (realpath(config.directname, guardrails_path) == NULL){
        perror("realpath");
        return NULL;
    } else{
        return guardrails_path;
    }
}


// char *getcwd(char *buf, size_t size);

int listDirect(char *path){
    struct dirent *de;
    DIR *dr = opendir(path);

    if (dr == NULL){
        printf("Can't open\n");
        return 1;
    }
    while ((de = readdir(dr)) != NULL){
        printf("Directory: %s\n", de->d_name);
    }

    closedir(dr);
    return 0;
}


// // listDirect();
// int main(void){
//     getInDirectory();
//     return 0;
// }