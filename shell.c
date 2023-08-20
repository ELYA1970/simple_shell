#include "main.h"
int main(int c, char **argv, char **env);
/**/
void free_arr(char **arrr)
{
	int i = 0;

	while (arrr[i])
	{	
		free(arrr[i]);
		i++;
	}
	free(arrr);
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
	char *arr[10];
	char *path;
	int status, i = 0, counter = 0, mode;
	pid_t pid;
	char *tok, *delim = {" \t\n\r"};

	(void)c;
	(void)path;

	mode = isatty(0);
	while (1)
	{
		counter++;
		if (mode == 1)
			write(1, "root$ ", 6);
		num_char = getline(&buff, &buff_size, stdin);
		if (num_char < 0)
		{
			errno = 0;
			/*_putchar('\n');*/
			free(buff);
			exit(errno);
		}
		buff[num_char - 1] = '\0';
		if (*buff != '\0')
		{
			if ((tok = strtok(buff, delim)) == NULL)
			{
				errno = 0;
				continue;
			}
			while (tok)
			{
				arr[i] = tok;
				tok = strtok(NULL, delim);
				i++;
			}
			arr[i] = NULL;
			if ((path = get_cmd(arr[0])) == NULL)
			{
				errno = 2;
				errmsg(argv[0], counter, arr[0]);
				continue;
			}
			pid = fork();
			if (pid == 0)
			{
				if (execve(path, arr, env) == -1)
				{
					errno = 2;
					errmsg(argv[0], counter, arr[0]);
					free(path);
					exit(errno);
				}

			}
			else
			{
				wait(&status);
			}
			i = 0;
		}
	}
	return (0);
}
