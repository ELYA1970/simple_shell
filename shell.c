#include "main.h"
/**
 * _strlen: count the lenght of a given string
 * @str: string to count
 * Return: string's lenght
 */
int _strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}
/**
 * main - Entry point
 * @c: arg counter
 * @argv: arg vector
 * @enc: enviroment variables
 * Return: 0 (success), else exit.
 */
int main(int c, char **argv, char **env)
{
	char *buff = NULL;
	size_t buff_size = 0;
	ssize_t num_char;
	char **arr;
	int status, i = 0;
	pid_t pid;
	char *tok, *delim = {" \t\n\r"};;

	(void)c;
	(void)env;
	(void)i;

	while (1)
	{
		write(1, "root$ ", 6);
		num_char = getline(&buff, &buff_size, stdin);
		if (num_char < 0)
		{
			errno = 0;
			perror("Exiting the shell ...");
			free(buff);
			exit(errno);
		}
		buff[num_char - 1] = '\0';
		if (*buff != '\0')
		{
			arr = malloc(sizeof(char *) * 1024);
			tok = strtok(buff, delim);
			while (tok)
			{
				arr[i] = tok;
				tok = strtok(NULL, delim);
				i++;
			}
			arr[i] = NULL;
			if (access(arr[0], F_OK) == -1)
			{
				errno = 2;
				perror(argv[0]);
				printf("access\n");
				free(arr);
				continue;
			}
			pid = fork();
			if (pid == 0)
			{
				if (execve(arr[0], arr, env) == -1)
				{
					errno = 2;
					perror(argv[0]);
					printf("execve\n");
					free(arr);
					exit(errno);
				}

			}
			else
			{
				wait(&status);
			}
			i = 0;
			free(arr);
		}
	}
	return (0);
}
