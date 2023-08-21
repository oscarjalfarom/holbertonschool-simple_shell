#include "main.h"

char *pathfinder(char *user_imput)
{
	char *path = NULL, *concat_path = NULL;	
	struct stat file_stats;
	char *token = NULL, *auxiliary_path = NULL;
	int i = 0;

	if (stat(user_imput, &file_stats) == 0)
		return (user_imput);
	path = _getEnvironmentValue("PATH");
	auxiliary_path = malloc(strlen(path) + 1);
	auxiliary_path = strcpy(auxiliary_path, path);
	token = strtok(auxiliary_path, ":\n");
	user_imput = string_concat("/", user_imput);

	while (token != NULL)
	{
		concat_path = string_concat(token, user_imput);

		if (stat(concat_path, &file_stats) == 0)
		{
			free(user_imput);
			free(auxiliary_path);
			return (concat_path);
		}
		free(concat_path);
		token = strtok(NULL, ":\n");
		i++;
	}
	free(user_imput);
	free(auxiliary_path);
	return (NULL);
}
