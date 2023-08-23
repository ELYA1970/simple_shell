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
#include <signal.h>
#include <errno.h>
/* home made functions */
void _putchar(char c);
char *_strtok(char *str, char *delimiter);
int _strcspn(char *str, char *str2);
char *_strchr(char *str, int c);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_getenv(char *name);
int _isdigit_str(char *str);
int _atoi(char *str);
int _isdigit(char c);
int checkmode(char *cmd);

void errmsg(char *argv, int counter, char *arr);

/* handle built-in commands */
int handle_exit(char **ar);

char *get_cmd(char *command, int mode);

#endif /*MAIN_H*/
