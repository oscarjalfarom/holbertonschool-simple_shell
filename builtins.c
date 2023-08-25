#include "main.h"

/**
 * builtin - Funtion that call the env or the exit
 * @comand: command a verificar
 * Return: return 1 if found exit or env, 0 if not
 */

int builtin(char *comand)
{
    if (strcmp(comand, "exit") == 0)
    {
        if (comand[4] == '\0') 
        {
            free(comand);
            exit(0); 
        }
        else
	{
            char **args = (char **)(comand + 5);
            int exit_status;

	    if (_isnumber(*args) && (exit_status = atoi(*args)) <= INT_MAX)
            {
                free(comand);
                custom_exit(exit_status);
            }
            else
            {
                perror("Invalid exit status");
                free(comand);
                return (2);
            }
        }
    }
    else if (strcmp(comand, "env") == 0)
    {
        display_environment_var();
        free(comand);
        return (1);
    }
    else
    {  
        return (0);
    }
    return (0);
}


/**
 * interruptHandler - interruot the process
 * @signal: signal
 * Return: not return
 */

void interruptHandler(int signal)
{
	(void) signal;
	write(STDIN_FILENO, "\n $ ", 4);
}


void custom_exit(int status)
{
    if (status >= 0 && status <= INT_MAX)
    {
        printf("Exiting with status %d\n", status);
        exit(status);
    }
    else
    {
        printf("Invalid exit status\n");
        exit(2);
    }
}


#include <stdbool.h>

bool _isnumber(const char *str)
{
    if (*str == '\0')
        return false;

    while (*str)
    {
        if (*str < '0' || *str > '9')
            return false;
        str++;
    }

    return true;
}
