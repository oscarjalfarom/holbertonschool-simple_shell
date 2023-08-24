#include "main.h"

int main(void)
{
    char *line = NULL;
    size_t buffer_size = 0;
    char **comand;
    char *full_path;
    int i;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "$ ", 2);
        
        if (getline(&line, &buffer_size, stdin) == -1)
        {
            if (feof(stdin))
            {
                write(STDOUT_FILENO, "\n", 1);
                free(line);
                exit(EXIT_SUCCESS);
            }
            perror("getline");
            exit(EXIT_FAILURE);
        }
        
        line[strlen(line) - 1] = '\0';

        comand = _malloc(sizeof(char *) * (strlen(line) + 1));
        if (!comand)
        {
            perror("Memory allocation error");
            free(line);
            exit(EXIT_FAILURE);
        }

        comand = getCommandArray(line, comand);
        if (comand == NULL || comand[0] == NULL)
        {
            free(comand);
            free(line);
            continue;
        }

        full_path = pathfinder(comand[0]);
        if (full_path)
        {
            execComand(full_path, comand[0]);
            free(full_path);
        }
        else
        {
            fprintf(stderr, "Command not found: %s\n", comand[0]);
        }

        i = 0;
        while (comand[i])
        {
            free(comand[i]);
            i++;
        }
        free(comand);
        free(line);
    }

    return 0;
}
