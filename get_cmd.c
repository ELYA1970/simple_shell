#include "main.h"
/**
 * get_cmd - get the full command
 * @command: string
 * Return: string that are the full command.
 */
char *get_cmd(char *command)
{
	char *path = NULL, *pathv = "PATH", *tok = NULL, *pathcpy = NULL;
	char *allcommand;
	struct stat ts;

	if (command[0] == '/')
	{
		if (access(command, F_OK) != 0)
			return (NULL);
		path = command;
		return (path);
	}
	path = _getenv(pathv);
	if (path != NULL)
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
