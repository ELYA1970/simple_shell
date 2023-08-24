#include "main.h"
/**
 * handle_exit - build exit command
 * @ar: array of pointers pointing to user's input
 * Return: 0 or status if exit, -1 if no exit found
 */
int handle_exit(char **ar)
{
	char *exit_str = "exit";
	int status = 0;

	if (_strcmp(ar[0], exit_str) == 0)
	{
		if (ar[1])
		{
			if (_isdigit_str(ar[1]))
			{
				status = _atoi(ar[1]);
				return (status);
			}
			return (-1);
		}
		return (0);
	}
	return (-1);
}
/**
 * handle_env - display current envirement
 * Return: (0)
*/
int handle_env(void)
{
	char **env = environ;
	int i = 0;
	while (env[i]) 
	{
		write(1, env[i], _strlen(env[i]));
		i++;
	}
	return (0);
}
