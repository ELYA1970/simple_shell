#include "main.h"
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
	write(2, argv, _strlen(argv));
	_putchar(':');
	_putchar(' ');
	fflush(stdout);
	if (counter < 10)
	_putchar(counter + '0');
	else if (counter >= 10 && counter < 100)
	{
		_putchar((counter / 10) + '0');
		_putchar((counter % 10) + '0');
	}
	else if (counter >= 100 && counter < 1000)
	{
		_putchar((counter / 100) + '0');
		_putchar(((counter / 10) % 10) + '0');
		_putchar((counter % 10) + '0');
	}
	_putchar(':');
	_putchar(' ');
	fflush(stdout);
	write(2, arr, _strlen(arr));
	_putchar(':');
	_putchar(' ');
	fflush(stdout);
	write(2, "not found\n", 10);
}
