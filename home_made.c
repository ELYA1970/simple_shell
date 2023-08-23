#include "main.h"
/**
 * _strlen - ccount len of string
 * @str: string to count
 * Return: return the count
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
/**
 * _strcmp - comparing two strings
 * @s1: string
 * @s2: string
 * Return: an integer 0 if are the same.
 */
int _strcmp(char *s1, char *s2)
{
	while (((*s1 != '\0') && (*s2 != '\0')) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
	{
		return (0);
	}

	else
	{
		return (*s1 - *s2);
	}
}

/**
 * _strcpy - that copies the string pointed to by src to dest
 * @src: string
 * @dest: string
 * Return: return a string aftrer copie
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0 ; src[i] != '\0' ; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - concatenates two strings
 * @dest: char
 * @src: char
 * Return: char
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _getenv - geting the value of an environnement key
 * @name: const char
 * Return: the value of the key like string.
 */
char *_getenv(char *name)
{
	char **ep;
	size_t len = _strlen(name);

	for (ep = __environ; *ep != NULL; ++ep)
	{
		if (!_strncmp(*ep, name, len) && (*ep)[len] == '=')
			return (&(*ep)[len + 1]);
	}
	return (NULL);
}
