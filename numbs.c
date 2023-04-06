#include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @p: paramater struct
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, parameters_t *p)
{
	static char *array;	
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)p;

	if (!(flags & CV_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CV_LCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @arg_list: argument pointer
 * @p: the parameters struct
 *
 * Return: bytes printed
 */
int print_unsigned(va_list arg_list, parameters_t *p)
{
	unsigned long l;

	if (p->l_mod)
		l = (unsigned long)va_arg(arg_list, unsigned long);
	else if (p->h_mod)
		l = (unsigned short int)va_arg(arg_list, unsigned int);
	else
		l = (unsigned int)va_arg(arg_list, unsigned int);
	p->unsign = 1;
	return (print_number(convert(l, 10, CV_UNSIGNED, p), p));
}



/**
 * print_address - prints addresss
 * @arg_list: argument pointer
 * @p: the parameters struct
 *
 * Return: bytes printed
 */
int print_address(va_list arg_list, parameters_t *p)
{
	unsigned long int n = va_arg(arg_list, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CV_UNSIGNED | CV_LCASE, p);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, p));
}
