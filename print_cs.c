#include "main.h"

/**
 * _putchar - prints a character literal
 * @c: The argument to print
 */

void _putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

/**
 * print_str - prints an array of character literal
 * @c: The argument to print
 * @len: The current len of characters
 * Return: len
 */

int print_str(char *c, int len)
{
	char *s; /* used by %s */

	s = c;
	if (c == NULL)
		s = "(null)";
	while (*s != '\0')
	{
		PRINT(*s);
		s++;
		len++;
	}
	return (len);
}
