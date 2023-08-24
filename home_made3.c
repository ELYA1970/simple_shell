#include "main.h"
/**
 * _isdigit - check if a charcter is a digit
 * @c: character to check
 * Return: 1 success 0 fails
*/
int _isdigit(char c)
{

	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/**
 * _atoi - select digit from a string
 * @str: string to check
 * Return: selected digit
*/
int _atoi(char *str)
{
	int i = 0;
	int signe = 1;
	int result = 0;

	while (str[i])
	{
		if (str[i] == '-' && _isdigit(str[i + 1]))
		{       signe = -1;
			i++;
		}
		if (_isdigit(str[i]))
			result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * signe);
}
/**
 * _isdigit_str - check if a string contain only digits
 * @str: string to check
 * Return: 1 (success) else 0
*/
int _isdigit_str(char *str)
{
	int i = 0;

	while (i  < _strlen(str))
	{
		if (!_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
