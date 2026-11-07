#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
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
    {START_CONNECTION_COMMAND, CMD_START_CONNECTION},
    {STOP_CONNECTION_COMMAND, CMD_STOP_CONNECTION},
    {START_COMMAND_COMMAND, CMD_START_COMMAND},
    {STOP_COMMAND_COMMAND, CMD_STOP_COMMAND},
    {START_LIMITATION_COMMAND, CMD_START_LIMITATION},
    {STOP_LIMITATION_COMMAND, CMD_STOP_LIMITATION},
};

enum Cmd lookup_cmd(const char *s) {
    for (size_t i = 0; i < sizeof cmd_table / sizeof *cmd_table; ++i) {
        if (strcmp(s, cmd_table[i].name) == 0) return cmd_table[i].cmd;
    }
    return CMD_UNKNOWN;
}

void execute_command(char **args){
    if (args == NULL || args[0] == NULL) {
        fprintf(stderr, "Provide a proper command\n");
        return;
    }

    fflush(stdout);
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return;
    }

    if (pid == 0){
        if (strcmp(args[0], "guard") != 0){
            printf("command not found, did you mean guard?\n");
            _exit(EXIT_FAILURE);
        }

        if (args[1] == NULL || args[2] != NULL) {
            fprintf(stderr, "Provide a proper command\n");
            _exit(EXIT_FAILURE);
        }

        {
            enum Cmd c = lookup_cmd(args[1]);
            switch (c)
            {
            case CMD_START_CONNECTION: startConnection(); break;
            case CMD_STOP_CONNECTION: stopConnection(); break;
            case CMD_START_COMMAND: startCommand(); break;
            case CMD_STOP_COMMAND: stopCommand(); break;
            case CMD_START_LIMITATION: startLimitation(); break;
            case CMD_STOP_LIMITATION: stopLimitation(); break;

            default:
                fprintf(stderr, "Provide a proper command\n");
                _exit(EXIT_FAILURE);
            }
        }

        fflush(stdout);
        _exit(EXIT_SUCCESS);
    }

    if (waitpid(pid, NULL, 0) < 0) {
        perror("waitpid");
    }
}