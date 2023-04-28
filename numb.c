#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of strings
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @p: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, parameters_t *p)
{
	unsigned int i = _strlen(str);
	int neg = (!p->unsign && *str == '-');

	if (!p->prec && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (p->prec != UINT_MAX)
		while (i++ < p->prec)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!p->minus_f)
		return (print_number_right_shift(str, p));
	else
		return (print_number_left_shift(str, p));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @p: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, parameters_t *p)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (p->zero_f && !p->minus_f)
		pad_char = '0';
	neg = neg2 = (!p->unsign && *str == '-');
	if (neg && i < p->width && pad_char == '0' && !p->minus_f)
		str++;
	else
		neg = 0;
	if ((p->plus_f && !neg2) ||
		(!p->plus_f && p->space_f && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (p->plus_f && !neg2 && pad_char == '0' && !p->unsign)
		n += _putchar('+');
	else if (!p->plus_f && p->space_f && !neg2 &&
		!p->unsign && p->zero_f)
		n += _putchar(' ');
	while (i++ < p->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (p->plus_f && !neg2 && pad_char == ' ' && !p->unsign)
		n += _putchar('+');
	else if (!p->plus_f && p->space_f && !neg2 &&
		!p->unsign && !p->zero_f)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @p: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, parameters_t *p)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (p->zero_f && !p->minus_f)
		pad_char = '0';
	neg = neg2 = (!p->unsign && *str == '-');
	if (neg && i < p->width && pad_char == '0' && !p->minus_f)
		str++;
	else
		neg = 0;

	if (p->plus_f && !neg2 && !p->unsign)
		n += _putchar('+'), i++;
	else if (p->space_f && !neg2 && !p->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < p->width)
		n += _putchar(pad_char);
	return (n);
}
