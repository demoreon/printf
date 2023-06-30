#include "main.h"

/**
 * get_specifier - validates the char if exist.
 * @chr: char to validate.
 * @args: list of variable auguments.
 * @len: char printed
 * Return: len of the printed char.
 */

int get_specifier(const char *chr, va_list *args, int len)
{
	int i = 0;
	int len_updated;
	find_spec func[] = {
		{"c", p_char}, {"s", p_str}, {"d", p_int}, {"i", p_int},
		{"%", p_percent}, {"b", p_binary}, {"u", p_usigned_int},
		{"o", p_octal}, {"x", p_hex}, {"X", p_hex}, {"S", p_str},
		{"p", p_addr},
		{NULL, NULL}
	};

	while (func[i].c != NULL)
	{
		if (strncmp(func[i].c, chr, 1) == 0)
		{
			if (*chr == 'X' || *chr == 'S')
				len += 2000;
			len_updated = func[i].func(args, len);
			break;
		}
		i++;
	}

	if (func[i].c == NULL)
	{
		PRINT(*(chr - 1));
		PRINT(*chr);
		len_updated = len + 2;
	}
	return (len_updated);
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
		if (*c == '%' && *(c + 1) == '\0')
			return (-1);
		if (*c == '%' && *(c + 1) != '\0')
		{
			len = get_specifier(++c, &args, len - 1);
		}
		else
			PRINT(*c);
		len++;
		c++;
	}
	return (len);
}
