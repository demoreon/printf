#include "main.h"

/**
 * get_specifier - finds the format function
 * @s: string of the format
 * Return: the number of bytes printed
 */

int (*get_specifier(char *s))(va_list arg_list, parameters_t *p)

{
	spec_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format function
 * @s: string of the format
 * @arg_list: argument pointer
 * @p: the parameters struct
 * Return: the number of bytes printed
 */

int get_print_func(char *s, va_list arg_list, parameters_t *p)
{
	int (*f)(va_list, parameters_t *) = get_specifier(s);

	if (f)
		return (f(arg_list, p));
	return (0);
}

/**
 * get_flag - finds the flag functions
 * @s: the format string
 * @p: the parameters struct
 * Return: if flag was valid
 */

int get_flag(char *s, parameters_t *p)

{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = p->plus_f = 1;
			break;
		case ' ':
			i = p->space_f = 1;
			break;
		case '#':
			i = p->hashtag_f = 1;
			break;
		case '-':
			i = p->minus_f = 1;
			break;
		case '0':
			i = p->zero_f = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier function
 * @s: string for format
 * @p: parameter structure
 * Return: if modifier was valid
 */

int get_modifier(char *s, parameters_t *p)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = p->h_mod = 1;
			break;
		case 'l':
			i = p->l_mod = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: the format strings
 * @p: the parameters structs
 * @arg_list: the argument pointers

 * Return: new pointer
 */

char *get_width(char *s, parameters_t *p, va_list arg_list)

	/* should this function use char **s and modify the pointer? */
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(arg_list, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	p->width = d;
	return (s);
}
