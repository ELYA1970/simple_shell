#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

char **Arr_token(char *str);
int _strlen(char *str);
int count_tokens(char *str, const char *delim);

#endif /*MAIN_H*/
