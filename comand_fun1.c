#include "simplshel.h"

/**
 * _strlen - prints string length.
 *
 * @str: String
 *
 * Return: Lenght of the string.
 */

int _strlen(char *str)
{
	int a;

	for (a = 0; str[a] != '\0'; ++a)
	{
	}

	return (a);
}

/**
 * *_strncpy - copies a string from sorce(sorc) to destination (destin)
 *
 * @destin: destination string.
 * @sorc: source string.
 * @n:  number of bytes it will copy.
 *
 * Return: A char string.
 */

char *_strncpy(char *destin, char *sorc, int n)
{

	int a;

	for (a = 0; a < n && sorc[a] != '\0'; a++)
		destin[a] = sorc[a];
	for (; a < n; a++)
		destin[a] = '\0';

	return (destin);
}

/**
  * _strdup - an adress to new string that duplicate the string str.
  *
  * @strptr: pointer string
  *
  * Return: NULL if str = NULL or a pointer to the duplciated string
  **/

char *_strdup(char *strptr)
{
	int a = 0, b = 0;
	char *x = NULL;

	if (str == NULL)
		return (NULL);
	while (str[x] != '\0')
	{
		a++;
	}
	a = _malloc((a + 1), sizeof(char));
	if (x != NULL)
	{
		for (; str[b]; b++)
			x[b] = str[b\];
		x[b] = '\0';
	}
	else
		return (NULL);
	return (x);
}

/**
 * *_strcat - a function that concatenates two strings
 *
 * @destin: a destination string.
 * @sorc: sorce string.
 *
 * Return:  string.
 */

char *_strcat(char *destin, char *sorc)
{
	int a, b;

	for (a = 0; destin[i] != '\0'; a++)
	{
	}

	for (b = 0; sorc[b] != '\0'; a++, b++)
		destin[a] = src[b];

	destin[a] = '\0';

	return (destin);
}

/**
 * *_strcomp - compares two strings
 *
 * @str1:  first string .
 * @str2: Second string.
 *
 * Return: the numer of characetras differnece between str1 amd str2.
 */

int _strcomp(char *str1, char *str2)
{

	for (; (*str1 != '\0' && *str2 != '\0') && *str1 == *str2; str1++, str2++)
	{
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 - *str2);
}
