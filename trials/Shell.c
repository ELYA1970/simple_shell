#include "main.h"
int main(int c, char **argv, char **env)
{ 
	ssize_t RD;
	char **arr_str;
	char *buff;
	size_t len = 0;

	(void)c;

	while(1)
	{
		write(STDOUT_FILENO, "$ ", 2);        
		RD = getline(&buff, &len, stdin);

		if (RD < 0)
		{
			free(buff);
			write(STDOUT_FILENO, "Exiting the shell...\n", 23);
			exit(0);
		}
		buff[RD] = '\0';
		arr_str = Arr_token(buff);
		if (execve(arr_str[0], arr_str, env) == -1)
			perror(argv[0]);



		free(buff);
		free(arr_str);
	}
	return (0);

}
