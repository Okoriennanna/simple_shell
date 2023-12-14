#include "simplshel.h"

/**
 * *stringcpy - copies a string.
 *
 * @ptrdestin: a destionation string pointer.
 * @ptrsorc: a ptr to source string
 *
 * Return: a char string
 */

char *stringcpy(char *ptrdestin, char *ptrsorc)
{
	int i;

	for (a = 0; ptrsorc[a] != '\0'; a++)
	{
		ptrdestin[a] = ptrsorc[a];
	}

	ptrdestin[a] = ('\0');
	return (ptrdestin);
}

/**
 * *_malloc1 - memory allocation for an array elements of size bytes.
 *
 * @num_arry: Number of array elements.
 * @size: size bytes of the element type.
 *
 * Return: Pointer to the allocated memory.
 */

void *_malloc1(unsigned int num_arry, unsigned int size)
{
	char *str;
	unsigned int a;

	if (num_arry == 0 || size == 0)
		return (NULL);

	str = malloc(num_arry * size);
	if (str == NULL)
		return (NULL);

	for (a = 0; a < (size * num_arry); a++)
		str[a] = 0;
	return (str);
}

/**
 * an_exit - Closes the program properly if the user types exit.
 *
 * @text: used to free memory.
 * @a: total of commands typed by user.
 * @comandl: 1st command typed by user.
 * @exit_status: exit status
 *
 * Return: Pointer to the allocated memory.
 */

void an_exit(char **text, int a, char *comandl, int exit_status)
{
	int b = 0;

	while (b < a)
	{
		free(text[b]);
		b++;
	}
	free(text);
	free(comandl);
	exit(exit_status);
}

/**
 * _envt - Prints the environment.
 *
 */

void _envt(void)
{
	unsigned int a;

	a = 0;
	while (environ[a] != NULL)
	{
		write(STDOUT_FILENO, environ[a], _strlen(environ[a]));
		a++;
	}
}

/**
 * sig_handl - Writes the prompt if CRL + c.
 * @signal: Previous value of the signal handler.
*/
void sig_handl(int signal __attribute__((unused)))
{
	write(STDOUT_FILENO, "\n:) ", 3);
}
