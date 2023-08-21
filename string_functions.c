#include "main.h"

char compare_strings(char *string1, char *string2, int max_length)
{
    	int i = 0;

    	while (i < max_length)
    	{
    		if (string1[i] == string2[i])
    			i++;
    		else if (string1[i] != string2[i])
    			return(-1);
    	}
    	return (0);
}

int string_length(char *string)
{
	int i = 0;

	while (*string != '\0')
	{
		i++;
		string++;
	}
	return (i);
}

char *string_concat(char *string1, char *string2)
{
    char *concat_string;
    int len1 = 0;
    int len2 = 0;
    int i = 0;

    if (string1 == NULL)
        string1 = "";
    if (string2 == NULL)
        string2 = "";

    while (string1[len1] != '\0')
        len1++;
    while (string2[len2] != '\0')
        len2++;

    concat_string = malloc(sizeof(char) * (len1 + len2 + 1));
    if (concat_string == NULL)
    {
        free(concat_string);
        return (NULL);
    }

    while (*string1)
    {
        concat_string[i] = *string1;
        i++;
        string1++;
    }
    while (*string2)
    {
        concat_string[i] = *string2;
        i++;
        string2++;
    }
    concat_string[i] = '\0';
    return (concat_string);
}
