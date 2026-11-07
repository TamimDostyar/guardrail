#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "configuration/configuration.h"
#include "isolation/isolate.h"


enum Cmd {
    CMD_UNKNOWN = 0,
    CMD_START_CONNECTION,
    CMD_STOP_CONNECTION,
    CMD_START_COMMAND,
    CMD_STOP_COMMAND,
    CMD_START_LIMITATION,
    CMD_STOP_LIMITATION
};
struct CmdMap { const char *name; enum Cmd cmd; };

static const struct CmdMap cmd_table[] = {
    {startConnection,  CMD_START_CONNECTION},
    {stopConnection,   CMD_STOP_CONNECTION},
    {startCommand,     CMD_START_COMMAND},
    {stopCommand,      CMD_STOP_COMMAND},
    {startLimitation,  CMD_START_LIMITATION},
    {stopCommand,   CMD_STOP_LIMITATION},
};

enum Cmd lookup_cmd(const char *s) {
    for (size_t i = 0; i < sizeof cmd_table / sizeof *cmd_table; ++i) {
        if (strcmp(s, cmd_table[i].name) == 0) return cmd_table[i].cmd;
    }
    return CMD_UNKNOWN;
}

void execute_command(char **args){

    pid_t pid = fork();

    if (pid == 0){
        printf("works fine\n"); 
    } else{
        exit(1);
    }

    while (args)
    {
        /* code */
        if (strcmp(args[0], "guard") != 0){
            printf("command not found, did you mean guard?\n");
        } else{
            
            enum Cmd c = lookup_cmd(args[1]);
            switch (c)
            {
            case CMD_START_CONNECTION: startConnection();
            case CMD_STOP_CONNECTION: stopConnection();
            case CMD_START_COMMAND: startCommand();
            case CMD_STOP_COMMAND: stopedCommand();
            case CMD_START_LIMITATION: startLimitation();
            case CMD_STOP_LIMITATION: stopLimitation();
            
            default:
                "Provide a proper command\n";
            }
        }

    }
    



}