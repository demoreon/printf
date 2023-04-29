#include "main.h"
#define PRINT(a) _putchar(a)

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

/**
 * _printf - a variadic function that can print an unknown number of args
 * @format: The argument to parse
 * Return: It returns the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	const char *c;
	int len;

	va_start(args, format);
	c = format;
	len = 0; /* length of the printf characters */

	if (c  == NULL)
		return (-1);
	while (*c != '\0')
	{
		if (*c == '%' && *(c + 1) != '\0')
		{
			switch (*(++c))
			{
			case 'c':
				PRINT(va_arg(args, int));
				break;
			case 's':
				len = print_str(va_arg(args, char *), len - 1);
				break;
			case '%':
				PRINT(*c);
				break;
			default:
				PRINT(*(c - 1));
				PRINT(*c);
				break;
			}
		}
		else
			if (*c == '%' && *(c + 1) == '\0')
				return (-1);
		else
			PRINT(*c);
		len++;
		c++;
	}
	return (len);
}
