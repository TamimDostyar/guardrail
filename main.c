#include <stdio.h>
#include "src/header/configuration/configuration.h"
#include "src/header/files/files.h"
#include "src/header/isolation/isolate.h"



int main(void){

    char *path = getInDirectory();
    printf("Path --> %s\n", path);

    startSystem(path);
    return 0;
}