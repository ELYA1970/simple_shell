#include "main.h"
int main(int c, char **argv, char **env);
/**
 * main - Entry point
 * @c: arg counter
 * @argv: arg vector
 * @env: enviroment variables
 * Return: 0 (success), else exit.
 */
int main(int c, char **argv, char **env)
{
	char *buff = NULL;
	size_t buff_size = 0;
	ssize_t num_char = 0;
	char *arr[100];
	char *path = NULL;
	int status, i = 0, counter = 0, mode, var;
	pid_t pid;
	char *tok, *delim = {" \t\n\r"};

	(void)c;
	(void)var;
	mode = isatty(0);
	while (1)
	{
		counter++;
		i = 0;
		if (mode == 1)
			write(1, "$ ", 2);
		num_char = getline(&buff, &buff_size, stdin);
		if (num_char < 0)
		{
			errno = 0;
		/*	_putchar('\n');*/
			free(buff);
			exit(errno);
		}
		buff[num_char - 1] = '\0';
		if (*buff != '\0')
		{
			tok = _strtok(buff, delim);
			if (tok == NULL)
			{
				errno = 0;
				continue;
			}
			while (tok)
			{
				arr[i] = tok;
				tok = _strtok(NULL, delim);
				i++;
			}
			arr[i] = NULL;
			path = get_cmd(arr[0]);
			if (path == NULL)
			{
				/*	if ((status = handle_exit(arr) >= 0))*/
				if (_strcmp(arr[0], "exit") == 0)
				{
					free(buff);
					exit(var);
				}
				else
				{
					errno = 2;
					errmsg(argv[0], counter, arr[0]);
					continue;
				}
			}
			else
			{
				pid = fork();
				if (pid < 0)
				{
					free(path);
					free(buff);
					exit(var);
				}
				else if (pid == 0)
				{
					if (execve(path, arr, env) == -1)
						errmsg(argv[0], counter, arr[0]);
					exit(var);
				}
				else
				{
					wait(&status);
					if (WIFEXITED(status) != 0)
						var = WEXITSTATUS(status);
					if (arr[0][0] != '/')
						free(path);
				}
			}
		}
	}
	return (0);
}
