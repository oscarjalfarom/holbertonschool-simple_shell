#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char *input;
    size_t len = 0;
    ssize_t read;

    while (1)
    {
        printf("($) ");
        read = getline(&input, &len, stdin);
        
        if (read == -1)
        {
            if (feof(stdin))
            {
                printf("\n");
                break;
            }
            else
            {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        if (input[read - 1] == '\n')
            input[read - 1] = '\0';

    }
    free(input);
    return 0;
}
