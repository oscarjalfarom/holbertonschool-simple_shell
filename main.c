#include "main.h"

/**
 * main - open shell, project base
 * Return: int
 */

 int main(void)
 {
 	char *buffer = NULL, **args;
 	size_t line_buffer_size = 0;
 	ssize_t buff_size = 0;
 	int status = 0;

 	while (1)
 	{
 		if (isatty(0))
 			printf("($) ");

 		buff_size = getline(&buffer, &line_buffer_size, stdin);
 		if (buff_size == -1 || _strcmp("exit\n", buffer) == 0)
 		{
 			free(buffer);
 			break;
 		}
 		buffer[buff_size - 1] = '\0';

 		if (_strcmp("env", buffer) == 0)
 		{
 			_env();
 			continue;
 		}

 		if (empty_line(buffer) == 1)
 		{
 			status = 0;
 			continue;
 		}

 		args = _split(buffer, "");
 		args[0] = search_path(args[0]);

 		if (args[0] != NULL)
 			status = execute(args);
 		else
 			perror("Error");
 		free(args);
 	}
 	return (status);
 }
