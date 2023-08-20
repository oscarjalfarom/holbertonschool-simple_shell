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
