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

char *_getEnvironmentValue(const char *name)
{
	int l = string_length((char *)name);
	char **envvar = environ;

	while (*envvar != NULL)
	{
		if (compare_strings(*envvar, (char *)name, l) == 0 && envvar[0][l] == '=')
			return (*envvar + l + 1);
		envvar++;
	}
	return (NULL);
}
