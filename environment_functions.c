#include "main.h"

int display_environment_var(void)
{
	char **envvar = environ;
	int i = 0;

	while (envvar[i])
	{
		write(1, envvar[i], string_length(envvar[i]));
		write(1, "\n", 1);
		++i;
	}
	return (1);
}
