#include "main.h"

void interruptHandler(int signal)
{
    (void) signal;
    write(STDOUT_FILENO, "\n$ ", 3);
}

void display_environment_var(void)
{
    char **envvar = environ;
    int i = 0;

    while (envvar[i])
    {
        write(STDOUT_FILENO, envvar[i], strlen(envvar[i]));
        write(STDOUT_FILENO, "\n", 1);
        ++i;
    }
}

void execComand(char *full_path, char *comand)
{
    pid_t child_pid;
    int status = 0;
    char *argv[2];
    argv[0] = comand;
    argv[1] = NULL;

    if (builtin(comand) == 0)
    {
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0)
        {
            signal(SIGINT, SIG_DFL);
            execve(full_path, argv, environ);
            perror("execve");
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(&status);
        }
    }
}


char **getCommandArray(char *line, char **command)
{
    char *line_copy, *token;
    int i;

    line_copy = _malloc(strlen(line) + 1);
    if (!line_copy)
        return NULL;

    strcpy(line_copy, line);
    token = strtok(line_copy, " \t\n");
    for (i = 0; token != NULL; i++)
    {
        command[i] = _malloc(strlen(token) + 1);
        if (!command[i])
        {
            free(line_copy);
            return NULL;
        }
        strcpy(command[i], token);
        token = strtok(NULL, " \t\n");
    }
    command[i] = NULL;
    free(line_copy);
    return command;
}

char *pathfinder(char *command)
{
    char *path, *path_copy, *path_token, *file_path;
    int command_length, directory_length;
    struct stat buffer;

    path = getenv("PATH");
    if (!path)
        return NULL;

    path_copy = strdup(path);
    command_length = strlen(command);
    path_token = strtok(path_copy, ":");
    while (path_token != NULL)
    {
        directory_length = strlen(path_token);
        file_path = malloc(command_length + directory_length + 2);
        if (!file_path)
        {
            free(path_copy);
            return NULL;
        }
        strcpy(file_path, path_token);
        strcat(file_path, "/");
        strcat(file_path, command);
        strcat(file_path, "\0");
        if (stat(file_path, &buffer) == 0)
        {
            free(path_copy);
            return file_path;
        }
        else
        {
            free(file_path);
            path_token = strtok(NULL, ":");
        }
    }
    free(path_copy);
    if (stat(command, &buffer) == 0)
        return strdup(command);
    return NULL;
}

int builtin(char *user_input)
{
    if (strcmp(user_input, "exit") == 0)
        exit(EXIT_SUCCESS);
    else if (strcmp(user_input, "env") == 0)
    {
        display_environment_var();
        return 1;
    }
    return 0;
}

void *_malloc(unsigned int size)
{
    void *memorySpace;

    memorySpace = malloc(size);
    if (!memorySpace)
    {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    return memorySpace;
}
