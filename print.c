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
 * _printf - a variadic function that can print an unknown number of args
 * @format: The argument to parse
 * Return: It returns the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	const char *c;
	int len;
	char *s; /* used by %s */

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
				s =  va_arg(args, char *);
				while (*s != '\0')
				{
					PRINT(*s);
					s++;
				}
				break;
			default:
				PRINT(*c);
				break;
			}
		}
		else
			_putchar(*c);
		c++;
		len++;
	}
	return (len);
}
