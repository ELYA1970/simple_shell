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
	int status = 0, i = 0, counter = 0, mode, var = 0, abs = 0, stats = 0;
	pid_t pid;
	char *tok, *delim = {" \t\n\r"};

	(void)c;
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
			/*	_putchar('\n');*/
			free(buff);
			exit(status);
		}
		buff[num_char - 1] = '\0';
		if (*buff != '\0')
		{
			tok = _strtok(buff, delim);
			if (tok == NULL)
				continue;
			while (tok)
			{
				arr[i] = tok;
				tok = _strtok(NULL, delim);
				i++;
			}
			arr[i] = NULL;
			abs = checkmode(arr[0]);
			path = get_cmd(arr[0], abs);
			if (path == NULL)
			{
				/*	if ((status = handle_exit(arr) >= 0))*/
				if (_strcmp(arr[0], "exit") == 0)
				{
					if (arr[1])
					{
						stats = handle_exit(arr[1]);
					if (stats)
					{
						free(buff);
						exit(stats);
					}
					}

					free(buff);
					exit(status);
				}
				else if (_strcmp(arr[0], "env") == 0)
				{
					handle_env();
					continue;
				}
				else
				{
					status = 127;
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
					exit(status);
				}
				else if (pid == 0)
				{
					if (execve(path, arr, env) == -1)
						errmsg(argv[0], counter, arr[0]);
					exit(status);
				}
				else
				{
					waitpid(pid, &var, 0);
					if (WIFEXITED(status) != 0)
						status = WEXITSTATUS(var);
					if (abs == 0)
						free(path);
				}
			}
		}
	}
	return (0);
}
