#ifndef CONFIG_H
#define CONFIG_H

const char startConnection[] = "--start-connection";
const char stopConnection[] = "--stop-connection";
const char startCommand[] = "--start-command";
const char stopCommand[] = "--stop-command";
const char startLimitation[] = "--start-limitation";
const char stopLimitation[] = "--stop-limitation";

struct Configuration
{
    char *directname;
    int check;
};


#endif