#include "main.h"
/**
 * checkmode - check for absolute path
 * @cmd: taked inpute from another function
 * Return: 1 if absolute, 0 if not
*/
int checkmode(char *cmd)
{
	int mode = 0, i = 0;

	while (cmd[i])
	{
		if (cmd[i] == '/')
			mode = 1;
		i++;
	}
	return (mode);
}
/**
 * get_cmd - get the full command
 * @command: string
 * @mode: integer
 * Return: string that are the full command.
 */
char *get_cmd(char *command, int mode)
{
	char *path = NULL, *pathv = "PATH", *tok = NULL, *pathcpy = NULL;
	char *allcommand;
	struct stat ts;

	path = _getenv(pathv);
	if (mode == 1)
	{
		if (access(command, F_OK) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	else if (path != NULL)
	{
		pathcpy = strdup(path);
		tok = _strtok(pathcpy, ":");
		if (tok != NULL)
		{
			while (tok)
			{
				allcommand = malloc(_strlen(tok) + _strlen(command) + 2);
				_strcpy(allcommand, tok);
				_strcat(allcommand, "/");
				_strcat(allcommand, command);
				if (stat(allcommand, &ts) == 0)
				{
					free(pathcpy);
					return (allcommand);
				}
				free(allcommand);
				tok = _strtok(NULL, ":");
			}
		}
		free(pathcpy);
	}

	return (NULL);
}
