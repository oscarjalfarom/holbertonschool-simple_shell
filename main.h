#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

void interruptHandler(int signal);
void display_environment_var(void);
void execComand(char *full_path, char *comand);
char **getCommandArray(char *line, char **command);
char *pathfinder(char *command);
int builtin(char *user_input);
void *_malloc(unsigned int size);

#endif
