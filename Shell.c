#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
void check_instruction(char *instruction);
/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	char *buff = NULL;
	size_t buff_size = 0;
	int num_char;
	char *tok;
	char **arr;
	int status, i = 0;
	pid_t pid;

	arr = malloc(sizeof(char *) * 1024);
	while (1)
	{
		write(1, "root$ ", 6);
		num_char = getline(&buff, &buff_size, stdin);
		tok = strtok(buff, " \t\n");
		if (num_char == -1)
		{
			printf("\n");
			free(buff);
			exit(0);
		}
		while (tok)
		{
			arr[i] = tok;
			tok = strtok(NULL, " \t\n");
			i++;
		}
		arr[i] = NULL;
		pid = fork();
		if (pid == 0)
		{
			if (execve(arr[0], arr, NULL) == -1)
				perror("execve");
		}
		else
		{
			wait(&status);
		}
		i = 0;
	}
	return (0);
}
