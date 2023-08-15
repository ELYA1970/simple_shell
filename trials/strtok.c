#include "main.h"
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
int count_tokens(char *str, const char *delim)
{
    int i = 0, j;
    int token_num = 0;
    
    while (str[i])
    {
        for (j = 0; delim[j]; j++)
        {
            if (delim[j] == str[i])
                token_num++;
            j++;
        }
        i++;
    }
    return (token_num);
}

char **Arr_token(char *str)
{
    char *token, *_str;
    char **Arr_tokens;
    const char *delim = " \t\n\r";
    int token_num, i = 0;

    token_num = count_tokens(str, delim);
    _str = strdup(str);
    Arr_tokens = malloc(token_num * sizeof(char *));
    token = strtok(_str, delim);
    while(token != NULL)
    {
        Arr_tokens[i] = malloc(sizeof(char) * _strlen(token));
        Arr_tokens[i] = token;
        i++;
        token = strtok(NULL, delim);
    }
    return (Arr_tokens);
}