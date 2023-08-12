#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
/****/

int _strlen(char *str)
{
    int count = 0, i = 0;
    while (str[i])
    {
    i++;
    count++;
    }
    return(count);
}

char *Arr_token(char *str)
{
    char *token;
    char *Arr_tokens;
    int i = 0, j = 0;

    Arr_tokens = malloc(_strlen(str) * sizeof(char *));
    token = strtok(str, " \\\t\n,;.");
while(token != NULL)
{
Arr_tokens[i] = *token;
i++;
token = strtok(NULL, " \\\t\n,;.");
}
Arr_tokens[i] = NULL;
    return (Arr_tokens);
}