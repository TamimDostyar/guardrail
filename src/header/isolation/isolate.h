#ifndef ISOLATE_H
#define ISOLATE_H

void startSystem(char *startPath);
void startConnection(void);
void stopConnection(void);
void startCommand(void);
void stopCommand(void);
void startLimitation(void);
void stopLimitation(void);

#endif