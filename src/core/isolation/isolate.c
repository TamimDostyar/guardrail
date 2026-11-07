#include <stdio.h>
#include "files/files.h"
#include "isolation/isolate.h"
#include <string.h>

void startSystem(char *startPath){

    if (strcmp(startPath, "/tmp/guardrails") == 0){
        printf("good to start\n");

    }
    else{
        printf("hold on son");
    }
}

void startConnection(){
    printf("connection started");
}

void stopConnection(){
    printf("connection stopped");
}


void startCommand(){
    printf("command started");
}

void stopedCommand(){
    printf("command stopped");
}

void startLimitation(){
    printf("limitation started");
}

void stopLimitation(){
    printf("limitation stopped");
}