#ifndef CONFIG_H
#define CONFIG_H

extern const char START_CONNECTION_COMMAND[];
extern const char STOP_CONNECTION_COMMAND[];
extern const char START_COMMAND_COMMAND[];
extern const char STOP_COMMAND_COMMAND[];
extern const char START_LIMITATION_COMMAND[];
extern const char STOP_LIMITATION_COMMAND[];

struct Configuration
{
    char *directname;
    int check;
};


#endif