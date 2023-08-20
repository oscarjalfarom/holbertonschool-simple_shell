#include "main.h"

int main(void)
{
    char *user_input[1024];
    char *token, *line = NULL;
    size_t i;
    int status = 0;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf(" $ ");
        
        if (getline(&line, &i, stdin) == EOF)
            break;
        
        if (*line == '\n' || *line == '\t')
            continue;
        
        token = strtok(line, " \t\n");
        if (token == NULL)
            continue;

        if (builtin(token) == 0)
        {
            pid_t _pid = fork();
            if (_pid == 0)
            {
                execve(token, user_input, environ);
                perror("./shell");
                free(line);
                exit(EXIT_FAILURE);
            }
            if (_pid > 0)
                wait(&status);
        }
        line = NULL, token = NULL;
    }
    
    free(line);
    exit(status);
}
