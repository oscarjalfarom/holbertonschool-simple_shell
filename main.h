#ifndef _MAIN_H
#define _MAIN_H

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

bool _isnumber(const char *str);
void custom_exit(int status);
void trim(char *str);
void display_environment_var(void);
char *pathfinder(char *command);
void interruptHandler(int signal);
int builtin(char *user_input);
void execComand(char *full_path, char **comand);
void removeExtraSpaces(char *str);

#endif
