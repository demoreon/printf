#include "main.h"

/**
 * print_char - prints character
 * @arg_list: argument pointer
 * @p: the parameter struct
 *
 * Return: number chars printed
 */
int print_char(va_list arg_list, parameters_t *p)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(arg_list, int);

	if (p->minus_f)
		sum += _putchar(ch);
	while (pad++ < p->width)
		sum += _putchar(pad_char);
	if (!p->minus_f)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - prints integer
 * @arg_list: argument pointer
 * @p: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list arg_list, parameters_t *p)
{
	long l;

	if (p->l_mod)
		l = va_arg(arg_list, long);
	else if (p->h_mod)
		l = (short int)va_arg(arg_list, int);
	else
		l = (int)va_arg(arg_list, int);
	return (print_number(convert(l, 10, 0, p), p));
}

/**
 * print_string - prints string
 * @arg_list: argument pointer
 * @p: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list arg_list, parameters_t *p)
{
	char *str = va_arg(arg_list, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)p;
	switch ((int)(!str))
		case 1:
			str = NULL_STR;

	j = pad = _strlen(str);
	if (p->prec < pad)
		j = pad = p->prec;

	if (p->minus_f)
	{
		if (p->prec != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < p->width)
		sum += _putchar(pad_char);
	if (!p->minus_f)
	{
		if (p->prec != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - Prints string
 * @arg_list: argument pointer
 * @p: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list arg_list, parameters_t *p)
{
	(void)arg_list;
	(void)p;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @arg_list: argument pointer
 * @p: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list arg_list, parameters_t *p)
{
	char *str = va_arg(arg_list, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STR));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, p);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
