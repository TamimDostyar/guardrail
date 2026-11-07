#include <stdio.h>
#include "src/header/configuration/configuration.h"
#include "src/header/files/files.h"
#include "src/header/isolation/isolate.h"
#include "src/header/shell/commandSys.h"



int main(int argc, char **argv){

    char *path = getInDirectory();
    printf("Path --> %s\n", path);

    startSystem(path);

    if (argc > 1) {
        execute_command(&argv[1]);
    }

    return 0;
}