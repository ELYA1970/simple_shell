#include "main.h"
/**
 * _strcspn - serch for first number of characters thar doeas not match
 * @str: string to check
 * @str2: string to match
 * Return: number of first characters not matching
*/
int _strcspn(char *str, char *str2)
{
	int i = 0, j = 0;
	ssize_t n = 0;

	while (str[i])
	{
		for (j = 0; str2[j]; j++)
		{
			if (str2[j] == str[i])
				return (n);
		}
		n++;
		i++;
	}
	return (n);
}

/**
 * _strncmp - compare up to n bytes of two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: numbre of bytes to compare
 * Return: 0 (success), difference if fails
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	int i = 0;

	while (n-- > 0 && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (*(unsigned char *) s1 - *(unsigned char *) s2);
		}
		i++;
	}
	if (n == 0)
	{
		return (0);
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
/**
 * _strchr - look for a character ineteger in a string
 * @str: string to check
 * @c: charaacter to match
 * Return: a pointer to the character found int the string
 *		NULL if no match found
*/
char *_strchr(char *str, int c)
{
	int i = 0;
	char *ret;

	while (str[i])
	{
		if (str[i] == c)
			return (ret = &str[i]);
		i++;
	}
	return (NULL);
}
/**
 * _strtok - tokenize a string by a given delimiter
 * @str: string to tokenize
 * @delimiter: charaters to delimit
 * Return: a pointer to the first token
 *		NULL  if nothing more delimiter found
*/
char *_strtok(char *str, char *delimiter)
{
	register int c;
	static char *next;
	char *tok;

	if (str == NULL)
		str = next;
	do {
		c = *str++;
		if (c  == '\0')
			return (NULL);
		tok = _strchr(delimiter, c);
	} while (tok);
	--str;
	next = str + _strcspn(str, delimiter);
	if (*next != '\0')
		*next++ = '\0';
	return (str);
}
