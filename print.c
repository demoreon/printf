#include "main.h"

/**
 * get_flag - validates the char if exist.
 * @chr: char to validate.
 * Return: flag code.
 */

int get_flag(const char *chr)
{
	if (strncmp(chr, "+ ", 2) == 0 || strncmp(chr, " +", 2) == 0)
		return (3);
	else if (*chr == ' ' || *chr == '+' || *chr == '#' || *chr == 'l')
		return (2);
	return (1);
}

/**
 * get_specifier - validates the char if exist.
 * @chr: char to validate.
 * @args: list of variable auguments.
 * @len: char printed
 * Return: len of the printed char.
 */
int get_specifier(const char *chr, va_list *args, int len)
{
	int fg, val, i = 0;
	find_spec func[] = {
		{"c", p_char}, {"s", p_str}, {"d", p_int}, {"i", p_int},
		{"%", p_percent}, {"b", p_binary}, {"u", p_usigned_int},
		{"o", p_octal}, {"x", p_hex}, {"X", p_hex}, {"S", p_str},
		{"p", p_addr}, {"+d", p_int}, {" d", p_int}, {"+ d", p_int},
		{" +d", p_int}, {"+i", p_int}, {" i", p_int}, {"+ i", p_int},
		{" +i", p_int}, {"#o", p_octal}, {"#d", p_int}, {"#i", p_int},
		{"#x", p_hex}, {"#X", p_hex}, {"s", p_str}, {"ld", p_lint},
		{"li", p_lint}, {"lo", p_int}, {"lu", p_int}, {"lx", p_int},
		{"lX", p_int}, {NULL, NULL}
	};
	fg = get_flag(chr);
	while (func[i].c != NULL)
	{
		if (strncmp(func[i].c, chr, fg) == 0)
		{
			if (*chr == 'X' || *chr == 'S')
				len += 2000;
			if (*chr == '#' && *(chr + 1) == 'X')
				len += 2000;
			if (fg > 1)
			{
				if (fg == 2 && *chr == 32)
					val = 2000;
				else if (fg == 2 && *chr == 35)
					val = 2500;
				else if (fg == 2 && *chr == 'l')
					val = 0;
				else
					val = 3000;
			}
			len = func[i].func(args, fg > 1 ? len + val : len);
			break;
		} i++;
	}

	if (func[i].c == NULL)
	{
		PRINT(*(chr - 1));
		PRINT(*chr);
		len += 2;
	} return (len);
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
		if (*c == '%' && *(c + 1) == 32 && *(c + 2) == '\0')
			return (-1);
		if (*c == '%' && *(c + 1) == 32 && *(c + 2) == '%')
		{
			PRINT('%');
			c += 2;
		} else if (*c == '%' && *(c + 1) != '\0')
		{
			len = get_specifier(++c, &args, --len);
			if (get_flag(c) == 3)
				c += 2;
			else if (get_flag(c) == 2 && *(c + 1) != '\0')
				c++;
		}
		else
			PRINT(*c);
		len++;
		c++;
	}
	return (len);
}
