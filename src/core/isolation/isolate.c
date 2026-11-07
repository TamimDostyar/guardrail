#include <stdio.h>
#include "files/files.h"
#include "isolation/isolate.h"
#include <string.h>

void startSystem(char *startPath){
    // char *startPath = getInDirectory();
    // int strcm

    
    if (strcmp(startPath, "/tmp/guardrails") == 0){
        printf("good to start\n");
    }
    else{
        printf("hold on son");
    }
}