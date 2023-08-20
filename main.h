#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void _putchar(char c);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

void errmsg(char *argv, int counter, char *arr);

char *_getenv(char *name);

int handle_built_ins(char *ar);
char *get_cmd(char *command);

void free_arr(char **arrr);


#endif /*MAIN_H*/
