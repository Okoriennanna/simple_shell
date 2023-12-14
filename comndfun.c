#include "simplshel.h"

/**
 * no_command - copies a string.
 *
 * @ptrd: pointer to destionation string.
 * @comand_lst: pointer to source string
 * @count: line counter
 * @argmt: argument vector
 *
 * Return: a char string
 */

void no_command(int ptrd, char **comand_lst, int count, char **argmt)
{
	int ln = 0;

	write(STDOUT_FILENO, argmt[0], _strlen(argmt[0]));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, ": ", 2);
	putint(count);
	write(STDOUT_FILENO, comand_lst[0], _strlen(comand_lst[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
	while (ln < ptrd)
	{
		free(comand_lst[ln]);
		ln++;
	}
	free(comand_lst);
}

/**
 * putint - function that prints an integer.
 *
 * @n: number
 *
 * Return: void
**/

void putint(int n)
{
	unsigned int i;

	if (n < 0)
	{
		i = -n;
		_putchr('-');
	}
	else
	{
		i = n;
	}
	if (i / 10)
	{
		putint(i / 10);
	}
	_putchr(i % 10 + '0');
}

/**
 * _putchr - writes the character c to stdout
 * @c: The character to print
 * Return: 0 (success).
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchr(char c)
{
	return (write(1, &c, 1));
}
