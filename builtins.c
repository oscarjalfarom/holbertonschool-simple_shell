#include "main.h"

/**
 * builtin - Funtion that call the env or the exit
 * @comand: command a verificar
 * Return: return 1 if found exit or env, 0 if not
 */

int builtin(char *comand)
{
        int is_builtin = 0;
	
	if (strcmp(comand, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
		is_builtin = 1;
	}
	else if (strcmp(comand, "env") == 0)
	{
		display_environment_var();
		is_builtin = 1;
	}
		return is_builtin;
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
