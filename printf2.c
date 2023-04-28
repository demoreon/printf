#include "main.h"

/**
 * print_hex - Prints unsigned hex numbers in lowercase
 * @arg_list: the argument pointer
 * @p: the parameters struct
 *
 * Return: bytes printed
 */
int print_hex(va_list arg_list, parameters_t *p)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (p->l_mod)
		l = (unsigned long)va_arg(arg_list, unsigned long);
	else if (p->h_mod)
		l = (unsigned short int)va_arg(arg_list, unsigned int);
	else
		l = (unsigned int)va_arg(arg_list, unsigned int);

	str = convert(l, 16, CV_UNSIGNED | CV_LCASE, p);
	if (p->hashtag_f && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	p->unsign = 1;
	return (c += print_number(str, p));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @arg_list: the argument pointer
 * @p: the parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list arg_list, parameters_t *p)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (p->l_mod)
		l = (unsigned long)va_arg(arg_list, unsigned long);
	else if (p->h_mod)
		l = (unsigned short int)va_arg(arg_list, unsigned int);
	else
		l = (unsigned int)va_arg(arg_list, unsigned int);

	str = convert(l, 16, CV_UNSIGNED, p);
	if (p->hashtag_f && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	p->unsign = 1;
	return (c += print_number(str, p));
}
/**
 * print_binary - prints unsigned binary number
 * @arg_list: the argument pointer
 * @p: the parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list arg_list, parameters_t *p)
{
	unsigned int n = va_arg(arg_list, unsigned int);
	char *str = convert(n, 2, CV_UNSIGNED, p);
	int c = 0;

	if (p->hashtag_f && n)
		*--str = '0';
	p->unsign = 1;
	return (c += print_number(str, p));
}

/**
 * print_octal - prints unsigned octal numbers
 * @arg_list: the argument pointer
 * @p: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list arg_list, parameters_t *p)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (p->l_mod)
		l = (unsigned long)va_arg(arg_list, unsigned long);
	else if (p->h_mod)
		l = (unsigned short int)va_arg(arg_list, unsigned int);
	else
		l = (unsigned int)va_arg(arg_list, unsigned int);
	str = convert(l, 8, CV_UNSIGNED, p);

	if (p->hashtag_f && l)
		*--str = '0';
	p->unsign = 1;
	return (c += print_number(str, p));
}
