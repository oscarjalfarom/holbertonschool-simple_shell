#include "main.h"

int main(void)
{
    char *user_input[1024];
    char *token, *line = NULL, *full_path = NULL;
    pid_t child_pid;
    size_t i, line_buffer_size;
    int status = 0;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf(" $ ");
        fflush(stdin);
        signal(SIGINT, interruptHandler);
        if (getline(&line, &line_buffer_size, stdin) == EOF)
            break;     
        if (*line == '\n' || *line == '\t')
            continue;
        token = strtok(line, " \t\n");
        for (i = 0; i < 1024 && token != NULL; i++)
            user_input[i] = token, token = strtok(NULL, " \t\n");
        user_input[i] = NULL;
        if (user_input[0] == NULL)
            continue;
        full_path = pathfinder(user_input[0]);
        if (builtin(user_input[0]) == 0)
        {
            child_pid = fork();
            if (child_pid == 0)
            {
                if (execve(full_path, user_input, environ))
                {
                    perror("execve"),free(line), exit(EXIT_FAILURE);
                }
            }   if (child_pid > 0)
                    wait(&status), free(line);
        }
        line = NULL, token = NULL, user_input[0] = NULL;
    }
    free(line), free(full_path), exit(status); 
}
