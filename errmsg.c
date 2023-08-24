#include "main.h"
/**
 * store_digit - store a digit into a string
 * @n: taked inpute from another function
 * Return: string containing the integer
 */
char *store_digit(long int n)
{
	int i = 0, temp1 = n, temp2 = n, len = 0;
	char *tmp, *str;

	while (temp1 > 0)
	{
		len++;
		temp1 /= 10;
	}
	tmp = malloc(len * sizeof(char) + 1);
	if (len > 1)
	{
		for (i = 0; i < len; i++)
		{
			tmp[i] = (temp2 % 10) + '0';
			temp2 /= 10;
		}
		tmp[i] = '\0';
	}
	else
	{
		tmp[i] = n  + '0';
		tmp[++i] = '\0';
	}
	str = malloc(len * sizeof(char) + 1);
	for (i = 0; i < len; i++)
	{
		str[i] = tmp[len - i - 1];
	}
	str[i] = '\0';
	free(tmp);
	return (str);

}
/**
 * _putchar - prints a char
 * @c: character
 * Return: void.
 */
void _putchar(char c)
{
	write(1, &c, 1);

}
/**
 * errmsg - display error message format
 * @argv: argumert vector
 * @counter: prompt counter
 * @arr: user command
 * Return: void.
 */
void errmsg(char *argv, int counter, char *arr)
{
	char *count;

	count = store_digit(counter);
	write(2, argv, _strlen(argv));
	write(2, ": ", 2);
	fflush(stderr);
	write(2, count, _strlen(count));
	write(2, ": ", 2);
	fflush(stderr);
	write(2, arr, _strlen(arr));
	write(2, ": ", 2);
	fflush(stderr);
	write(2, "not found\n", 10);
	free(count);
}
/**
 * err_exit - ras
 * @argv: ras
 * @counter: ras
 * @arr: rrsa
 * @v: eaf
 * Return: vois.
*/
void err_exit(char *argv, int counter, char *arr, char *v)
{
	char *count;

	count = store_digit(counter);
	write(2, argv, _strlen(argv));
	write(2, ": ", 2);
	fflush(stderr);
	write(2, count, _strlen(count));
	write(2, ": ", 2);
	fflush(stderr);
	write(2, arr, _strlen(arr));
	write(2, ": ", 2);
	fflush(stderr);
	write(2, "Illegal number", 15);
	write(2, ": ", 2);
	fflush(stderr);
	write(2, v, _strlen(v));
	free(count);
}
