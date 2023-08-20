#ifndef _MAIN_H
#define _MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
int builtin(char *user_input);
char compare_strings(char *string1, char *string2, int max_length);
int string_length(char *string);
int display_environment_var(void);

#endif 
