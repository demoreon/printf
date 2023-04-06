#include "main.h"

/**
 * get_precision - gets the prec from the format string
 * @s: the format string
 * @p: the parameters struct
 * @arg_list: the argument pointer
 * Return: new pointer
*/

char *get_precision(char *s, parameters_t *p, va_list arg_list)
{
	int d = 0;

	if (*s != '.')
		return (s);
	s++;
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
	p->prec = d;
	return (s);
}
