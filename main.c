#include <stdio.h>
#include "src/header/configuration/configuration.h"
#include "src/header/files/files.h"


int main(void){

    char *path = getInDirectory();
    printf("Path --> %s", path);
    return 0;
}